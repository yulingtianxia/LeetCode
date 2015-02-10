//
//  133	Clone Graph.cpp
//  LeetCode
//
//  Created by 杨萧玉 on 15/2/10.
//  Copyright (c) 2015年 杨萧玉. All rights reserved.
//

#include "commonheader.h"
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<int, UndirectedGraphNode *> label2Node;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        UndirectedGraphNode *newNode=new UndirectedGraphNode(node->label);
        label2Node[node->label]=newNode;
        vector<UndirectedGraphNode *>::iterator iter=node->neighbors.begin();
        for (; iter!=node->neighbors.end(); iter++) {
            if (label2Node.find((*iter)->label)==label2Node.end()) {
                newNode->neighbors.push_back(cloneGraph(*iter));
            }
            else{
                newNode->neighbors.push_back(label2Node[(*iter)->label]);
            }
        }
        return newNode;
    }
};