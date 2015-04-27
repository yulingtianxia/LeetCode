//
//  71	Simplify Path.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/4/27.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    stack<string> dirs;
    string dir;
    string result="";
    string simplifyPath(string path) {
        if (path.back()!='/') {
            path+="/";
        }
        for (auto ch:path) {
            if (ch=='/') {
                if (dir.length()>0) {
                    if (dir=="..") {
                        if (!dirs.empty()) {
                            dirs.pop();
                        }
                    }
                    else if (dir!=".") {
                        dirs.push(dir);
                    }
                    dir.clear();
                }
                continue;
            }
            dir.push_back(ch);
        }
        if (dirs.empty()) {
            return "/";
        }
        while (!dirs.empty()) {
            result.insert(0, "/"+dirs.top());
            dirs.pop();
        }
        return result;
    }
};