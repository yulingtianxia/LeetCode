//
//  155	Min Stack.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class MinStack {
    stack<int> vec;
    stack<int> min;
public:
    void push(int x) {
        vec.push(x);
        if (!min.size()||x<=min.top()) {
            min.push(x);
        }
    }
    
    void pop() {
        if (vec.top()==min.top()) {
            min.pop();
        }
        vec.pop();
    }
    
    int top() {
        return vec.top();
    }
    
    int getMin() {
        return min.top();
    }
};
