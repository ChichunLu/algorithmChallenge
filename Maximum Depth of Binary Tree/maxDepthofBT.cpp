//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by CHI-CHUN LU on 2017/5/1.
//  Copyright © 2017年 CHI-CHUN LU. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

struct TreeNode* newNode(int val){
    struct TreeNode* Node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    Node -> val = val;
    Node -> left = NULL;
    Node -> right = NULL;
    
    return Node;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else{
            int rDepth = maxDepth(root->right);
            int lDepth = maxDepth(root->left);
            
            return rDepth>lDepth? rDepth+1:lDepth+1;
        }
    }
};

int main() {
    
    int ans;
    Solution rel;
    
    struct TreeNode *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    
    ans = rel.maxDepth(root);
    cout<<ans<<endl;
    
    return 0;
}
