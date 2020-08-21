import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=101 lang=java
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root);
    }

    public boolean isMirrorRecursion(TreeNode l, TreeNode r) {
        if (l == null && r == null)
            return true;
        if (l == null || r == null)
            return false;
        return (l.val == r.val) && isMirrorRecursion(l.left, r.right) && isMirrorRecursion(l.right, r.left);
    }

    public boolean isMirror(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode l = queue.poll();
            TreeNode r = queue.poll();
            if (l == null && r == null)
                continue;
            if (l == null || r == null)
                return false;
            if (l.val != r.val)
                return false;

            queue.add(l.left);
            queue.add(r.right);
            queue.add(r.left);
            queue.add(l.right);
        }
        return true;
    }
}
// @lc code=end
