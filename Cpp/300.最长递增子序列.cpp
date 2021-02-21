/**
	动态规划，每次计算dp[i]之前，dp[0...i-1]都计算出来，每次遍历之前的dp，最后得到结果
**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int dp[len];
        memset(dp,0,sizeof(dp));
        int ans = 1;
        dp[0] = 1;

        for (int i = 1;i < len;i++) {
            dp[i] = 1;
            for (int j = 0;j < i;j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(dp[i],ans);
        }

        return ans;
    }
};
