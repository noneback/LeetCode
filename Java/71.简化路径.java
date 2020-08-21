/*
 * @lc app=leetcode.cn id=71 lang=java
 *
 * [71] 简化路径
 */
import java.util.Stack;

// @lc code=start
class Solution {
    public String simplifyPath(String path) {
        StringBuffer ret = new StringBuffer();
        Stack<String> stack = new Stack<>();
        String[] cons = path.split("/");
        for (int i = 0; i < cons.length; i++) {
            if (cons[i].equals("") || cons[i].equals("."))
                continue;
            if (cons[i].equals("..")) {
                if (!stack.isEmpty())
                    stack.pop();
            } else {
                stack.push(cons[i]);
            }
        }
        if (stack.isEmpty())
            return "/";
        for (int i = 0; i < stack.size(); i++) {
            ret.append("/");
            ret.append(stack.get(i));
        }
        return ret.toString();

    }
}
// @lc code=end
