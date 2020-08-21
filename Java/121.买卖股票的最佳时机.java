import javax.tools.ForwardingJavaFileManager;

/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2 || prices == null)
            return 0;
        int min = prices[0], max = prices[0], sum = 0, mid = 0;
        for (int i = 0; i < prices.length; i++) {
            mid = prices[i] - min;
            if (mid > 0) {
                if (sum < mid)
                    sum = mid;
            } else {
                min = prices[i];
            }
        }
        return sum;
    }

}

// @lc code=end
