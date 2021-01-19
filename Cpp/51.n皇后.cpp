/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
#include <string.h>
#include <string>
#include <vector>
using namespace std;
class Solution 
{
 private:
  vector<vector<string>> ans;

 public:
  vector<vector<string>> solveNQueens(int n) {
    int marks[n];
    bool flags[n];
    for (int i = 0; i < n; i++) flags[i] = false;
    permute(0, n, marks, flags);
    return ans;
  }

  void permute(int index, int n, int marks[], bool flags[]) {
    //退出条件
    if (index == n) {
      ans.push_back(toString(marks, n));
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!flags[i]) {
        bool flag = true;
        for (int j = index-1; j >= 0 && flag; j--)
          flag = !(abs(marks[j] - i) == abs(j - index));

        if (flag) {
          marks[index] = i;
          flags[i] = true;
          permute(index + 1, n, marks, flags);
          flags[i] = false;
        }
      }
    }
  }

  vector<string> toString(int marks[], int n) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
      string ret = "";
      for (int j = 0; j < n; j++) {
        ret += j == marks[i] ? "Q" : ".";
      }
      answer.push_back(ret);
    }
    return answer;
  }
};
// @lc code=end
