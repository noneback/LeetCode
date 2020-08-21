import java.util.LinkedList;
import java.util.Stack;
import java.util.concurrent.LinkedBlockingDeque;

import javax.swing.tree.TreeNode;

import org.graalvm.compiler.core.common.alloc.Trace;

import jdk.nashorn.api.tree.Tree;

/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        LinkedList<Integer> ret=new LinkedList<>();
        TreeNode t=root;
        while(!stack.isEmpty()||t!=null){
            while(t!=null){
                stack.push(t);
                ret.addFirst(t.val);
                t=t.right;
            }

            if(!stack.isEmpty()){
                t=stack.pop();
                t=t.left;
            }
        }
        return (List) ret;
        }
}
// @lc code=end
