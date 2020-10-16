/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  unordered_map<char, int> map, window;

 public:
  bool compare() {
    for (const auto &item : map) {
      if (window[item.first] != window[item.second]) return false;
    }
    return true;
  }

  string minWindow(string s, string t) {

    if (s.length() < t.length()) return "";

    for (int i = 0; i < t.length(); i++) map[t[i]]++;

    int r = 0, l = 0, len = INT_MAX, ansL = -1, ansR = -1;
    for (const auto &ch : s) {
      if (map[ch] != window[ch]) {
        window[ch]++;
        map.
      }
      r++;

      while (compare() && l <= r) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          ansL = l;
        }
        if(map.find(s[l])!=map.end()){
          --window[l];
        }
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, len);
  }
};
// @lc code=end
