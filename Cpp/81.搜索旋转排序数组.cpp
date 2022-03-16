class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }

    bool binary_search(int l, int r, const vector<int> &nums, int target) {
        // 直接对半二分查找，最还也是O(n)
        if (l > r) return false;
        int mid = ((r - l) >> 1) + l;
        if (nums[mid] == target) {
            return true;
        }
        return binary_search(l, mid - 1, nums,target) || binary_search(mid + 1, r, nums,target);
    }
};
