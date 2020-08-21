/*
 * @lc app=leetcode.cn id=242 lang=javascript
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  if (s === t) return true;
  if (s.length !== t.length) return false;
  let map = new Array(26).fill(0);
  let ch_num = 'a'.charCodeAt(0);
  for (let i in s) {
    map[s[i].charCodeAt() - ch_num]++;
    map[t[i].charCodeAt() - ch_num]--;
  }

  return map.every(t => t === 0);
};
// @lc code=end
