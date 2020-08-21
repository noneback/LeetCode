/*
 * @lc app=leetcode.cn id=122 lang=java
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<2||prices==null) return 0;
        int t = prices[0], sum = 0, mid = 0;
        for (int i = 1; i < prices.length; i++) {
            mid = prices[i] - t;
            if (mid > 0)
                sum += mid;
            t=prices[i];
        }
        return sum;

    }
}
// @lc code=end
