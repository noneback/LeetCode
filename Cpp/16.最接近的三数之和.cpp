class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = -9999;
        for (int i = 0;i < nums.size();i++){
            int l = i+1,r = nums.size()-1;
            while (l < r) {
                int total = nums[l] + nums[r] + nums[i];
                if (abs(target - total) < abs(target - sum)) sum = total;
                if (total < target){
                    l++;
                } else if (total > target){
                    r--;
                } else {
                    return target;
                }
            }
        }
        return sum;
    }
};
