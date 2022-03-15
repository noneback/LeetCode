class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto &n : nums) {
            if (i < 2 || n != nums[i - 2]) {  // 利用了数组的有序性和结果的重复性
                nums[i++] = n;
            }
        }
        return i;
    }
};
