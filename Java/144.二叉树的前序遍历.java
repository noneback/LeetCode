import java.util.LinkedList;

import jdk.nashorn.internal.runtime.regexp.joni.Syntax;
import sun.awt.image.ImageWatched.Link;

/*
 * @lc app=leetcode.cn id=144 lang=java
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        LinkedList<Integer> ret = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        // stack.push(root);
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                ret.add(root.val);
                stack.push(root);
                root = root.left;
            }
            if (!stack.isEmpty()) {
                root = stack.pop();
                root = root.right;
            }

        }
        return (List) ret;

    }
}
// @lc code=end
