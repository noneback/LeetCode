/*
 * @lc app=leetcode.cn id=125 lang=javascript
 *
 * [125] 验证回文串
 */

// @lc code=start
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  let i = 0,
    j = s.length - 1;
  if (s.length === 0 || i === j) return true;
  let reg = /[a-zA-Z0-9]/;
  while (i < j) {
    while (!reg.test(s[i])) i++;
    while (!reg.test(s[j])) j--;
    if (i < j && s[i++].toLowerCase() !== s[j--].toLowerCase()) return false;
  }
  return true;
};

// @lc code=end
