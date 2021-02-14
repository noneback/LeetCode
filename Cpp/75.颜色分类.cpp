/**
	荷兰旗问题，一边扫描
**/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        int i = 0;
        while (p0 < p2 && i <= p2) {
            while (nums[i] == 2 && p2 >= i) {
                swap(nums[i],nums[p2]);
                p2--;
            }
            if (nums[i] == 0) {
                swap(nums[i],nums[p0]);
                p0++;
            }
            i++;
        }
    }
};


/**
	两遍扫描
**/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hash[3];
        memset(hash, 0, sizeof(hash));
        for (auto i : nums) {
            hash[i]++;
        }
        int j = 0;
        for (int i = 0;i < 3;i++) {
          
            while (hash[i]) {
                nums[j] = i;
                hash[i]--;
                j++;
            }
        }

    }
};
