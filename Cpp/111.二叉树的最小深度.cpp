/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root) {
        if (!root) return INT_MAX;
        if (!root->left && !root->right) return 1;
        return 1 + min(helper(root->left), helper(root->right));
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return helper(root);
    }
};
// @lc code=end

