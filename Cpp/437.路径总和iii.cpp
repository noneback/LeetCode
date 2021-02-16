/**
	思路就是遍历，利用两层递归的手法，dfs
**/
class Solution {
public:
    int cnt = 0;
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        sumSubTree(root, sum);
        pathSum(root -> left, sum);
        pathSum(root -> right, sum);
        return cnt;
    }

    void sumSubTree(TreeNode* root, int left) {
        if (!root) return ;
        if (left - root -> val == 0) cnt++;
        sumSubTree(root -> left, left - root -> val);
        sumSubTree(root -> right, left - root -> val);
    }
};
