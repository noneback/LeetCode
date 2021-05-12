/*
	前缀和 + hashmap优化
	
	关键词：数组，连续，求和等
	
	- 前缀和减少重复的求和计算
	
	- hashmap减少没有必要的遍历以及查询
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        hashmap[0]++;

        int sum = 0;
        int cnt = 0;
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            cnt += hashmap[sum - k];
            hashmap[sum]++; // 放在最后，防止重复计算
        }

        return cnt;      
    }
};
