class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 3;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
            int one = nums[i];
            for (int j = i + 1;j < nums.size() - 2;++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue; // 去重
                int two = nums[j];
                int l = j + 1, r = nums.size() - 1;
                while (l < nums.size() && l < r) {
                    long tmp = (long)one + two +  nums[l] + nums[r];
                    if (tmp == target) {
                        ans.emplace_back(vector{one, two, nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) l++; // 去重
                        while (l < r && nums[r] == nums[r + 1]) r--; // 去重
                    } else if (tmp > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }

        return ans;

    }
};
