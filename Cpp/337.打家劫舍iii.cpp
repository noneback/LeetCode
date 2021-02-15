/**
	树形动态规划，一般利用hash表，TreeNode作为Key,求最优解
**/
class Solution {
    
public:
    unordered_map<TreeNode*,int> f, g;
    int rob(TreeNode* root) {
        dfs(root);
        return max(g[root],f[root]);
    }

    void dfs(TreeNode* root) {
        if (!root) return ;
        dfs(root -> left);
        dfs(root -> right);
        
        f[root] = root -> val + g[root -> left] + g[root -> right];
        g[root] = max(g[root -> left],f[root -> left]) + max(g[root -> right],f[root -> right]);
    }
};
