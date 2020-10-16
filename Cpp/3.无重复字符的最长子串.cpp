/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <math.h>
#include <string.h>

#include <string>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int _max = 0;
    int index[256];
    memset(index, -1, sizeof(index));

    int beg = -1;
    for (int i = 0; i < s.length(); i++) {
      if (index[s[i]] > beg) beg = index[s[i]];
      index[s[i]] = i;
      _max = max(_max, i - beg);
    }
    return _max;
  }
};
// @lc code=end
