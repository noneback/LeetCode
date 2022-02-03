/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool ans = true;
    int height(TreeNode* root) {
        if (!root) return 0;
        if (!ans) return 0;
        auto l = height(root->left), r = height(root->right);
        if (abs(l - r) > 1) {
            ans = false;
        }
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};
// @lc code=end

