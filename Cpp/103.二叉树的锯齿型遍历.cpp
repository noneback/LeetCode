/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
使用了deque双端队列作为每一层数值的容器，通过插入头部或者尾部，实现zigzag
*/

 
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;

        while (!q.empty()) {
            deque<int> ans;
            int len = q.size();

            for (int i = 0;i < len;i++) {
                TreeNode* cur = q.front();
                q.pop();
                                
                if (odd) ans.push_back(cur -> val);  
                else ans.push_front(cur -> val);  

                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);

            }

            odd = !odd;
            ret.emplace_back(vector<int>{ans.begin(),ans.end()});
            
        }
        return ret;
        }

};
