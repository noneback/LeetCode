import java.util.LinkedList;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=103 lang=java
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<Integer> level = new LinkedList<>();
        LinkedList<List<Integer>> ret = new LinkedList<>();
        LinkedList<TreeNode> list2 = new LinkedList<>();
        LinkedList<TreeNode> list;
        list2.add(root);
        boolean flag = false;
        while (!list2.isEmpty()) {
            list = new LinkedList<>();
            while (!list2.isEmpty()) {

                TreeNode node = list2.poll();
                if (node != null)
                    level.add(node.val);
                if (flag) {
                    if (node.right != null)
                        list.add(node.right);
                    if (node.left != null)
                        list.add(node.left);
                } else {
                    if (node.left != null)
                        list.add(node.left);
                    if (node.right != null)
                        list.add(node.right);
                }
                flag = !flag;
            }
            if(level !=null||level.size()==0)
                ret.add(level);
            level.clear();
            list2 = list;

        }

        return (List) ret;
    }

}
// @lc code=end
