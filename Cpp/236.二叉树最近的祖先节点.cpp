/**
	递归法: lflag 和 rflag 判断p与q节点位于那个子树中，第一个满足(lflag && rflag) || ((root -> val == p -> val || root -> val == q -> val) && (lflag || rflag)条件的节点是所求祖先节点
	迭代法: 用map记录父节点，直到找到p,q,在寻找最近祖先节点
*/

class Solution {
public:
    bool dfs(TreeNode* root,TreeNode** ans,TreeNode *p,TreeNode *q) {
        if (root == nullptr) return false;
        bool lflag = dfs(root -> left,ans,p,q);
        bool rflag = dfs(root -> right,ans,p,q);
        if ((lflag && rflag) || ((root -> val == p -> val || root -> val == q -> val) && (lflag || rflag))) {
            *ans = root;
        }
        return lflag || rflag || (root -> val == p -> val || root -> val == q -> val);
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans;
        dfs(root,&ans,p,q);
        return ans;
    }
};


class Solution {
    
public:
    unordered_map<int,TreeNode*> fMap;
    unordered_map<int,bool> visited;

    void dfs(TreeNode* root) {
        if (root -> left) {
            fMap[root -> left -> val] = root;
            dfs(root -> left);
        }

        if (root -> right) {
            fMap[root -> right -> val] = root;
            dfs(root -> right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fMap[root-> val] = nullptr;
        dfs(root);

        while (p) {
            visited[p -> val] = true;
            p = fMap[p -> val];
        }

        while (q) {
            // 从q往上走，第一个visited
            if (visited[q -> val]) return q;
            q = fMap[q -> val];
        }
        return nullptr;
    }
};
