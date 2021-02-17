/**
	将计算拆解为计算左右元素乘积，得到左右乘积表，再求解
**/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int leftMul[nums.size()],rightMul[nums.size()];
        memset(leftMul,1,sizeof(leftMul));
        memset(leftMul,1,sizeof(rightMul));
        int left = 1, right = 1, len = nums.size();
        for (int i = 0;i < nums.size();i++) {
            leftMul[i] = left;
            rightMul[len - 1 - i] = right;
            left *= nums[i];
            right *= nums[len - 1 - i];
        }

        for (int i = 0;i < len;i++) {
            res.push_back(leftMul[i] * rightMul[i]);
        }
        return res;
    }
};
