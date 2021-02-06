/**
	维护一个rightmost，表示右边最远到达，类似动态规划和贪心
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightMost = 0;
        for (int i = 0;i < nums.size();i++) {
            if (rightMost < i) return false;
            if (rightMost >= nums.size() - 1) return true;
            rightMost = max(rightMost, i + nums[i]);
        }
        return false;
    }
};
