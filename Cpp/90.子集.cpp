class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() + 1;i++) {
            vector<int> tmp;
            backTrack(nums, i, 0, 0, tmp);
        }
        return ans;
    }


    void backTrack(vector<int> &nums, int len, int idx, int begin, vector<int> &tmp) {
        if (tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }

        while (idx != begin && idx < nums.size() && nums[idx] == nums[idx - 1]) idx++; // remove duplicated
        if (idx >= nums.size()) return;

        tmp.push_back(nums[idx]);
        backTrack(nums, len, idx + 1, idx + 1, tmp);
        tmp.pop_back();
        backTrack(nums, len, idx + 1, begin, tmp);
    }
};
