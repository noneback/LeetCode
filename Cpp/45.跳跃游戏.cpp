class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPoi = 0, end = 0, steps = 0;

        for (int i = 0;i < nums.size() - 1;i++) {
            maxPoi = max(i + nums[i], maxPoi); // 维护一个下次跳跃最远的距离
            if (i == end) { // 重点，当i==end时，必然更新end
                end = maxPoi;
                steps++;
            }
        }
        return steps;
    }
};
