import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=98 lang=java
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private LinkedList<Integer> list = new LinkedList<>();

    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        inter(list, root);

        int len = list.size();

        for (int i = 0; i < len - 1; i++) {
            if (list.get(i) >= list.get(i + 1))
                return false;
        }

        return true;

    }

    public void inter(List list, TreeNode root) {
        if (root != null) {
            inter(list, root.left);
            list.add(root.val);
            inter(list, root.right);

        }

    }

}
// @lc code=end
