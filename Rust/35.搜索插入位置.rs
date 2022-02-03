/*
 * @lc app=leetcode.cn id=35 lang=rust
 *
 * [35] 搜索插入位置
 */

// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        let mut ans = nums.len();
        // find the first >= target, insert into front
        while l <= r {
            let mid = (r - l) / 2 + l;
            if nums[mid] < target {
                l = mid + 1;
            } else if nums[mid] >= target {
                ans = mid;
                if mid == 0 {
                    return mid as i32;
                }
                r = mid - 1;
            }
        }
        return ans as i32;
    }
}
// @lc code=end
