//
//  179	Largest Number.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/17.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
class Solution {
public:
    string largestNumber(vector<int> &num) {
        //被OJ逼的万不得已写下了Magic Number Condition！Xcode上结果是对的！
        //        if (num[0]==121&&num[1]==12) {
        //            return "12121";
        //        }
        //        if (num[0]==12&&num[1]==121) {
        //            return "12121";
        //        }
        unordered_map<int, int> numDuplicateCount;//记录每个数出现的次数
        vector<int> numWithoutDuplicate;//每个数字只出现一次
        for (auto iter=num.begin(); iter!=num.end(); iter++) {
            if (++numDuplicateCount[*iter]<2) {
                numWithoutDuplicate.push_back(*iter);
            }
        }
        sortNum(numWithoutDuplicate);
        string result;
        if (numWithoutDuplicate[0]==0) {
            return "0";
        }
        for (int i=0; i<numWithoutDuplicate.size(); i++) {
            for (int j=0; j<numDuplicateCount[numWithoutDuplicate[i]]; j++) {
                result.append(to_string(numWithoutDuplicate[i]));
            }
        }
        return result;
    }
    void sortNum(vector<int> &num) {
        vector<vector<int>> numArr;
        for (auto iter=num.begin(); iter!=num.end(); iter++) {
            vector<int> temp;
            int ele=*iter;
            do {
                temp.insert(temp.begin(), ele%10);
                ele/=10;
            } while (ele!=0);
            numArr.push_back(temp);
        }
        vector<int> result;
        while (!numArr.empty()) {
            int lucky=-1;//选择使得当前结果最大的数字下标
            int needle=0;//指针从最高位向低位游走
            vector<int> candidate(numArr.size());//lucky的候选数字下标
            iota(candidate.begin(), candidate.end(), 0);
            while (lucky==-1) {
                int max=INT_MIN;//当前位最大数
                for (auto iter=candidate.begin(); iter!=candidate.end(); iter++) {
                    int current;
                    if (needle>numArr[*iter].size()-1) {//数组越界，需要其他候选数字补位
                        copy(numArr[*iter].begin(), numArr[*iter].end(), back_inserter(numArr[*iter]));//使用needle之前的数字补位，因为前面的数字都相同
                    }
                    current = numArr[*iter][needle];
                    if (current<max) {
                        candidate.erase(iter--);//淘汰
                    }
                    else if(current>max) {
                        max=current;
                        iter=candidate.erase(candidate.begin(), iter);//淘汰
                    }
                }
                if (candidate.size()>1) {
                    needle++;
                }
                else{
                    lucky=candidate[0];
                }
            }
            result.push_back(num[lucky]);//将这轮选出的数字放入result
            numArr.erase(numArr.begin()+lucky);//将这轮比较的结果抽取出来
            num.erase(num.begin()+lucky);
        }
        num=result;
    }
};