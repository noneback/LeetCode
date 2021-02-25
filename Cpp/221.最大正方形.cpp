/**
	动态规划，dp[i][j]代表以matrix[i][j]为右下角的最大边长。dp[i][j]只与dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j]有关
**/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int row = matrix.size(), col = matrix[0].size();
        int dp[row + 1][col + 1];
        memset(dp,0,sizeof(dp));
        int ans = 0;

        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (matrix[i][j] == '0') continue;

                if (i - 1 < 0 || j - 1 < 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i][j - 1],min(dp[i - 1][j],dp[i - 1][j - 1])) + 1;
                }
                
                ans = max(dp[i][j],ans);
            }
        }
        return ans * ans;
    }
};
