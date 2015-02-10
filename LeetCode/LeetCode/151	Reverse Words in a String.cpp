//
//  151	Reverse Words in a String.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length()==0) {
            return;
        }
        string::iterator it = s.begin();
        string word;
        string result;
        for (; it!=s.end(); it++) {
            if (*it!=' ') {
                word+=*it;
            }
            else{
                if (it!=s.begin()&&*(it-1)!=' ') {
                    result.insert(0, word+" ");
                }
                word="";
            }
        }
        if (word!="") {
            result.insert(0, word+" ");
        }
        if (result[result.length()-1]==' ') {
            result.erase(result.end()-1);
        }
        s=result;
    }
};