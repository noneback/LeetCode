class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1,-1};

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = ((r - l) >> 1) + l;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        if (l >= nums.size() || nums[l] != target) return ret;

        ret[0] = l;

        l = 0 ,r = nums.size();
        while (l < r) {
            int mid = ((r - l) >> 1) + l;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid;
        }

        ret[1] = l - 1;

        return ret;
    }



};
