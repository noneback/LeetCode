class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        int dp[n + 1];
        memset(dp,0,sizeof(dp));

        for (int i = 1;i <= n;i++) {
            dp[i] = dp[i - 1] + 1;

            for (int j = 2;i - j * j >= 0;j++) {
                dp[i] = min(dp[i - j * j] + 1,dp[i]);
            }
        }

        return dp[n];
    }
};
