/**
	将环拆解为两个线性list，分别求最有解，得到结果
**/


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int dp[2][nums.size() + 1];
        memset(dp,0,sizeof(dp));
        // last has been steal
        dp[0][1] = 0; // not selected
        dp[1][1] = nums[0]; // selected

        for (int i = 2;i < nums.size() + 1;i++) {
            dp[0][i] = max(dp[0][i - 2] + nums[i - 1], dp[0][i - 1]);
            dp[1][i] = max(dp[1][i - 2] + nums[i - 1], dp[1][i - 1]);
        }
        return max(dp[0][nums.size()],dp[1][nums.size() - 1]);

    }
};
