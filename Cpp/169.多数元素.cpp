/**
	摩尔投票算法（消消乐（x））
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //if (nums.size() == 0) return 0;
        int count = 0;
        int candidate = nums[0];
        for (int i = 0;i < nums.size();i++) {
            if (!count) candidate = nums[i];
            count = candidate == nums[i] ? count + 1 : count - 1;
        }
        return candidate;
    }
};
