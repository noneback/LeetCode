import java.util.Stack;

import jdk.vm.ci.aarch64.AArch64.Flag;

/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        // boolean ret = false;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            switch (ch) {

            case '(':
            case '{':
            case '[':
                stack.push(ch);
                break;
            case ')':
                if (stack.isEmpty() || stack.pop() != '(')
                    return false;
                break;

            case '}':
                if (stack.isEmpty() || stack.pop() != '{')
                    return false;
                break;
            case ']':
                if (stack.isEmpty() || stack.pop() != '[')
                    return false;
                break;
            default:
                break;
            }
        }
        if (!stack.isEmpty())
            return false;
        return true;
    }

}

// @lc code=end
