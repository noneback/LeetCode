/**
	动态规划
**/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int dp[nums.size() + 2];
        memset(dp, 0, sizeof(dp));

        dp[1] = nums[0];
        for (int i = 2;i <= nums.size();i++) {
            dp[i] = max(dp[i - 1],nums[i - 1] + dp[i - 2]);
        }
        return dp[nums.size()];
    }
};
