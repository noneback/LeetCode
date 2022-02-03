/*
 * @lc app=leetcode.cn id=58 lang=rust
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut last_word_len = 0;
        let mut cur_len = 0;

        for ch in s.chars() {
            if ch == ' ' {
                last_word_len = if cur_len == 0 { last_word_len } else{ cur_len };
                cur_len = 0;
            } else {
                cur_len += 1;
            }
        }
        return if cur_len == 0 { last_word_len } else{ cur_len };
    }
}
// @lc code=end

