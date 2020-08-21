/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let map = new Map()
    for (let i in nums) {
        let t = target - nums[i];
        if (map.has(t)) {
            return [Math.min(i, map.get(t)), Math.max(i, map.get(t))];
        } else {
            map.set(nums[i], i);
        }
    }
    return [-1, -1];

};
// @lc code=end