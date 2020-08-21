import java.util.Random;

/*
 * @lc app=leetcode.cn id=384 lang=java
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
    private int[] nums = null;

    public Solution(int[] nums) {
        this.nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] ret = new int[nums.length], mid = new int[nums.length];
        int size=nums.length;
        for (int i = 0; i < size; i++) {
            mid[i] = nums[i];
        }
        Random random = new Random();
        int t;
        for (int i = 0; i < mid.length; i++) {
            t=random.nextInt(size);
            ret[i]=mid[t];
            mid[t]=mid[--size];
        }
        return ret;
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(nums); int[] param_1 = obj.reset(); int[] param_2 =
 * obj.shuffle();
 */
// @lc code=end
