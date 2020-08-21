/*
 * @lc app=leetcode.cn id=50 lang=java
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {

    public double fastPow(double x, int n) {
        if (n == 0)
            return 1;
        double t = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return t * t;
        } else {
            return t * t * x;
        }

    }

    public double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return fastPow(x, n);

    }
}
// @lc code=end
