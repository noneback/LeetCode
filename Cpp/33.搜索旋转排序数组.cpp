class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size() - 1,target);
    }

    int binarySearch (vector<int> &nums, int l, int r,int target) {
        if (l > r) return -1;
        int mid = l + ((r - l) >> 1);

        if (nums[mid] == target) return mid;

        int ret = binarySearch(nums,mid + 1,r,target);
        if (ret != -1) return ret;

        ret = binarySearch(nums,l,mid - 1,target);
        if (ret != -1) return ret;

        return -1;


    };

};
