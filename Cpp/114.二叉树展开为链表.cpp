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

 /**
	常规是利用先序遍历，在组织节点
	最佳是每次找到右节点的前序节点，再将两者相连
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while (cur) {
            if (cur -> left){
                TreeNode* next = cur -> left;
                TreeNode* predecessor = next;
                while (predecessor -> right) {
                    predecessor = predecessor -> right;
                }

                predecessor -> right = cur -> right;
                cur -> left = nullptr;
                cur -> right = next;
            }
            cur = cur -> right;
        }

    }
};
