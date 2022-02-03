/*
 * @lc app=leetcode.cn id=67 lang=rust
 *
 * [67] 二进制求和
 */
use std::cmp;
// @lc code=start
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
       format!("{:b}",u128::from_str_radix(&a, 2).unwrap() + u128::from_str_radix(&b, 2).unwrap())
    }
}
// @lc code=end

