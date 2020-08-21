import java.util.Stack;
/*
 * @lc app=leetcode.cn id=227 lang=java
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
    public  int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        String str = toPost(s);
        String[] datas = str.split(" ");
        for (String x : datas) {
            if (x.equals(""))
                continue;
            if (x.matches("[0-9]+"))
                stack.push(Integer.parseInt(x));
            else {
                if (stack.size() >= 2) {
                    int a = stack.pop(), b = stack.pop();
                    if (x.trim().equals("+")) {
                        stack.push(a + b);
                    } else if (x.trim().equals("*")) {
                        stack.push(b * a);
                    } else if (x.trim().equals("-")) {
                        stack.push(b - a);
                    } else if (x.trim().equals("/")) {
                        stack.push(b / a);
                    }
                }
            }
        }
        return stack.pop();
    }

    public  String toPost(String s) {
        StringBuffer ret = new StringBuffer();
        // "3+2*2/2*3+2-39"
        Stack<Character> stack = new Stack<>();
        char t = 0;
        for (char x : s.toCharArray()) {
            if (Character.isDigit(x)) {
                ret.append(x);
            } else if (x == '+' || x == '-') {
                ret.append(" ");
                if (stack.empty()) {
                    stack.push(x);
                    continue;
                } else {
                    t = stack.peek();
                    if (t == '+' || t == '-') {
                        ret.append(stack.pop());
                    } else {
                        while (!stack.empty()) {
                            ret.append(stack.pop());
                            ret.append(" ");
                        }

                    }
                    stack.push(x);
                    ret.append(" ");
                }

            } else if (x == '*' || x == '/') {
                ret.append(" ");
                if (stack.empty()) {
                    stack.push(x);
                    continue;
                } else {
                    t = stack.peek();
                    if (t == '*' || t == '/') {

                        ret.append(stack.pop());
                    }
                    stack.push(x);
                    ret.append(" ");
                }

            }

        }
        while (!stack.isEmpty()) {
            ret.append(" ");
            ret.append(stack.pop());

        }
        return ret.toString();

    }

}