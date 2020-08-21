import java.util.List;

/*
 * @lc app=leetcode.cn id=95 lang=java
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {
        if(n==0) return new LinkedList<TreeNode>();
        else return generate_trees(1, n);
    }

    private List<TreeNode> generate_trees(int start,int end){
        List<TreeNode> all_trees=new LinkedList<TreeNode>();
        if(start>end) {
            all_trees.add(null);
            return all_trees;
        };
        
        for (int i = start; i < end+1; i++) {
            List<TreeNode> l_trees=generate_trees(start,i-1);
            List<TreeNode> r_trees=generate_trees(i+1,end);
            for (TreeNode  lNode : l_trees) {
                for (TreeNode rNode : r_trees) {
                    TreeNode t=new TreeNode(i);
                    t.left=lNode;
                    t.right=rNode;
                    all_trees.add(t);
                }
                
            }
    }
    return all_trees;
        
    }
}
// @lc code=end
