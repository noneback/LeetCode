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
	首先要理解前序遍历和中序遍历的规则：
		- 中序遍历
			- 先遍历根节点；
			
			- 随后递归地遍历左子树；
			
			- 最后递归地遍历右子树。

		- 前序遍历
			- 先递归地遍历左子树；
			
			- 随后遍历根节点；
			
			- 最后递归地遍历右子树。
	有:
	- 对于任意一颗树而言，前序遍历的形式总是
	
	[ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
	
	即根节点总是前序遍历中的第一个节点。
	
	- 中序遍历的形式总是
	
	[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]

	所以可以首先通过前序遍历找到pre_root，接着定位到in_root，如此递归构建出子树。


 */
class Solution {
public:
    unordered_map<int,int> m;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0;i < inorder.size();i++) {
            m[inorder[i]] = i;
        }

        return myBuildTree(preorder,inorder,0,preorder.size() - 1,0 ,inorder.size() - 1);

    }

    TreeNode* myBuildTree(vector<int> &preorder,vector<int>&inorder,int preorder_l,int preorder_r,int inorder_l,int inorder_r) {
        if (preorder_l > preorder_r) {
            return nullptr;
        }

        int pre_root = preorder_l;
        int in_root = m[preorder[pre_root]];

        TreeNode* root = new TreeNode{preorder[pre_root]};

        int size_left_subtree = in_root - inorder_l;

        root -> left = myBuildTree(preorder,inorder,preorder_l + 1,preorder_l + size_left_subtree,inorder_l,in_root - 1);
        root -> right = myBuildTree(preorder,inorder,preorder_l + size_left_subtree + 1,preorder_r,in_root + 1,inorder_r);
        return root;


    }
};
