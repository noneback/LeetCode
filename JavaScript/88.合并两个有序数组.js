/*
 * @lc app=leetcode.cn id=88 lang=javascript
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
/**
 * @param {number[]} nums1_t
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1_t in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
  let i = m - 1,
    j = n - 1,
    end = m + n - 1;

  while (i > -1 && j > -1) {
    nums1[end--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
  }

  if (i === -1) {
    while (j > -1) nums1[end--] = nums2[j--];
  } else {
    while (i > -1) nums1[end--] = nums1[i--];
  }
};
// @lc code=end
