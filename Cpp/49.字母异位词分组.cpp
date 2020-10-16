/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 private:
  vector<vector<string>> ans;

 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<map<char, int>> vm;
    for (auto str : strs) {
      map<char, int> m;
      for (auto ch : str) {
        m[ch]++;
      }
      bool flag = false;
      for (int i = 0; i < vm.size(); i++) {
        if (vm[i] == m) {
          ans[i].push_back(str);
          flag = true;
          break;
        }
      }
      if (flag) continue;
      vector<string> v;
      v.push_back(str);
      ans.push_back(v);

      vm.push_back(m);
    }
    return ans;
  }
};
// @lc code=end
