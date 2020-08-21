import java.util.LinkedList;
import java.util.Queue;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<Integer> result = new LinkedList<>();
        TreeNode temp = root;
        Stack<TreeNode> stack = new Stack<>();
        while (temp !=null||!stack.isEmpty()) {
            while (temp!=null){
                stack.push(temp);
                temp = temp.left;
            }
            if(!stack.isEmpty()){
                temp =stack.pop();
                result.add(temp.val);
                temp = temp.right;
            }
        }
        return result;
    }
}
// @lc code=end
