//
//  main.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 14/11/27.
//  Copyright (c) 2014年 杨萧玉. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <numeric>
#include <limits>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    set<pair<int , int>> lands;
    int numIslands(vector<vector<char>> &grid) {
        int result=0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]=='1'&&lands.find(pair<int, int>(i,j))==lands.end()) {
                    searchAround(i, j, grid);
                    result++;
                }
            }
        }
        return result;
    }
    void searchAround(int i,int j,vector<vector<char>> &grid) {
        if (lands.find(pair<int, int>(i,j))==lands.end()) {
            lands.insert(pair<int, int>(i,j));
            if (i+1<grid.size()&&grid[i+1][j]=='1') {
                searchAround(i+1, j, grid);
            }
            if (j+1<grid[0].size()&&grid[i][j+1]=='1') {
                searchAround(i, j+1, grid);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();

    return 0;
}