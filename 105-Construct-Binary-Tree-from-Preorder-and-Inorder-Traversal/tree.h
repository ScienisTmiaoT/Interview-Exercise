//
// Created by Marvin on 2017/7/21.
//

#ifndef INC_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_TREE_H
#define INC_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_TREE_H

#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

/*
 * 前序遍历：先访问根节点再访问左右节点（子树）
 * 中序遍历：访问左节点（子树）-根节点-右节点（子树）
 * 后序遍历：先访问左右节点（子树）再访问根节点
 */
/*
 * 这道题的解题思路就是递归，我们知道前序遍历的第一个元素是根节点，在中序遍历中，根节点的两边
 * 分别为左右子树，因此根据这种逻辑关系可以递归地构建整棵树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int plen = preorder.size(), ilen = inorder.size();
        if(plen == 0 || ilen == 0) return NULL;
        return tool(preorder, inorder, 0, plen - 1, 0, ilen - 1);
    }

    TreeNode* tool(std::vector<int>& preorder, std::vector<int>& inorder, int
    ps, int pe, int is, int ie) {
        if(ps > pe) return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        int index = 0;
        //找到每棵树的根节点
        for(int i = is; i <= ie; i++)
            if(inorder[i] == node->val) {
                index = i;
                break;
            }
        node->left = tool(preorder, inorder, ps + 1, ps + index - is, is, index - 1);
        //第三个参数为pe - (ie - index) + 1
        node->right = tool(preorder, inorder, pe - ie + index + 1, pe, index + 1, ie);
        return node;
    }
    void preorder(TreeNode* node) {
        if(node == NULL) return;
        std::cout << node->val;
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(TreeNode* node) {
        if(node == NULL) return;
        inorder(node->left);
        std::cout << node->val;
        inorder(node->right);
    }
};
#endif //INC_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_TREE_H
