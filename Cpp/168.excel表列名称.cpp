/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string ans{""};
    while (columnNumber > 0) {
      ans = static_cast<char>(('A' + (columnNumber - 1) % 26)) + ans;
      columnNumber = (columnNumber - 1) / 26;
    }
    return ans;
  }
};
// @lc code=end
