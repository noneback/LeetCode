/**
 * 关键在于理解对于一个长度为 NN 的数组，其中没有出现的最小正整数只能在 [1, N+1][1,N+1] 中。
 * 这是因为如果 [1, N][1,N] 都出现了，那么答案是 N+1N+1，否则答案是 [1, N][1,N] 中没有出现的最小正整数。
 * 利用原有空间，是空间复杂度最低
 * 哈希表或者置换法
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size()+1;
        for (auto &num : nums) {
            if (num <= 0) num = len; 
        }
        
        for (int i = 0;i < len - 1;i++) {
           int seq = abs(nums[i]);
           if (seq < len){
               nums[seq-1] = -abs(nums[seq-1]);
           }
        }

        int i = 0;
        for (;i < nums.size() && nums[i] < 0;i++) ;
        return i+1;
    }
};
