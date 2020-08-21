/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        LinkedList<LinkedList<Integer>> result = new LinkedList<LinkedList<Integer>>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        LinkedList<TreeNode> tQueue = new LinkedList<>();
        TreeNode temp = null;
        LinkedList<Integer> list = new LinkedList<>();
        if (root != null)
            list.add(root.val);
        if (root != null)
            queue.add(root);
        // result.add(list);

        while (!queue.isEmpty()) {
            LinkedList<TreeNode> tempList = new LinkedList<>();
            list = new LinkedList<Integer>();
            while (!queue.isEmpty()) {
                temp = queue.poll();
                if (temp != null)
                    list.add(temp.val);
                if (temp.left != null)
                    tempList.add(temp.left);
                if (temp.right != null)
                    tempList.add(temp.right);// 25
            }
            result.add(list);
            queue = tempList;
        }
        return (List) result;

    }
}
// @lc code=end
