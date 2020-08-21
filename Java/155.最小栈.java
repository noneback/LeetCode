import java.util.PriorityQueue;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=155 lang=java
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    //private int min = Integer.MAX_VALUE;
    private Stack<Integer> stack = new Stack<>();
    private PriorityQueue<Integer> queue = new PriorityQueue<>();

    /** initialize your data structure here. */
    public MinStack() {
    }

    public void push(int x) {
        stack.push(x);
        queue.add(x);
    }

    public void pop() {
        queue.remove(stack.peek());
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
      return queue.element();
    }
}

/**
 * Your MinStack object will be instantiated and called as such: MinStack obj =
 * new MinStack(); obj.push(x); obj.pop(); int param_3 = obj.top(); int param_4
 * = obj.getMin();
 */
// @lc code=end
