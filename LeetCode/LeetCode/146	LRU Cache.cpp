//
//  146	LRU Cache.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class LRUCache{
public:
    LRUCache(int capacity) : cap_(capacity) {
        
    }
    
    int get(int key) {
        int ans = -1;
        auto it = dic.find(key);
        if (it != dic.end()) {
            ans = it->second->second;
            data_.erase(it->second);
            data_.push_front(make_pair(key, ans));
            dic[key] = data_.begin();
        }
        return ans;
    }
    
    void set(int key, int value) {
        auto it = dic.find(key);
        if (it != dic.end()) {
            data_.erase(it->second);
        }
        data_.push_front(make_pair(key, value));
        dic[key] = data_.begin();
        if (dic.size() > cap_) {
            int rKey = data_.rbegin()->first;
            data_.pop_back();
            dic.erase(rKey);
        }
    }
private:
    int cap_;
    list< pair<int, int> > data_;
    unordered_map<int, list< pair<int, int> >::iterator > dic;
};