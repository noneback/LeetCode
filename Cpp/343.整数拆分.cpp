/**
	动态规划
**/


class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;

        int dp[n + 4];
        memset(dp,0,sizeof(dp));
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4;i <= n;i++) {
            dp[i] = i;
            for (int j = 2;j <= i / 2 + 1;j++) {
                dp[i] = max(dp[i],dp[i - j] * dp[j]);
            }
        }

        return dp[n];
    }
};
