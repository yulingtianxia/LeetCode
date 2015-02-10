//
//  18	4Sum.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size()<4) {
            return result;
        }
        sort(num.begin(), num.end());
        vector<int>::iterator iter = num.begin();
        int pos=1;
        for (; iter!=num.end()-3; iter++,pos++) {
            if (iter!=num.begin()&&*iter==*(iter-1)) {
                continue;
            }
            vector<int> temp(num.size()-pos);
            copy(num.begin()+pos, num.end(), temp.begin());
            int newTarget=target-(*iter);
            threeSum(temp, newTarget,*iter);
        }
        return result;
    }
    void threeSum(vector<int> &num, int target,int num1) {
        vector<int>::iterator iter = num.begin();
        int pos=1;
        for (; iter!=num.end()-2; iter++,pos++) {
            if (iter!=num.begin()&&*iter==*(iter-1)) {
                continue;
            }
            vector<int> temp(num.size()-pos);
            copy(num.begin()+pos, num.end(), temp.begin());
            int newTarget=target-(*iter);
            twoSum(temp, newTarget,num1,*iter);
        }
    }
    void twoSum(vector<int> &numbers, int target,int num1,int num2) {
        int l=0;
        int r=(int)numbers.size()-1;
        int sum = numbers[l]+numbers[r];
        for (; l<r;sum = numbers[l]+numbers[r]) {
            if ((r<numbers.size()-1&&numbers[r]==numbers[r+1])||sum>target) {
                r--;
            }
            else if((l>0&&numbers[l]==numbers[l-1])||sum<target){
                l++;
            }
            else{
                vector<int> temp={num1,num2,numbers[l++],numbers[r--]};
                result.push_back(temp);
            }
        }
    }
};