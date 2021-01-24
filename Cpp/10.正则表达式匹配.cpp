/*
动态规划问题，重点要关注出现 '*' 的情况，具体见题解
[题解](https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/)

除此之外，还需要注意base case, dp[0][*]相关状态的初始化。

*/


class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.length() + 1][p.length() + 1]; //dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;

		// 初始化，处理诸如 s = "abbc" , p = "c*a*b*c"，第一个匹配字符为空但匹配依然成立的情况
        for (int i = 2;i < p.length() + 1;i++) {
            dp[0][i] = p[i-1] == '*' && dp[0][i-2];
        }

     
        for (int i = 1;i < s.length() + 1;i++) {
            for (int j = 1;j < p.length() + 1;j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (j > 1 && p[j-2] != s[i-1] && p[j-2] != '.') {
                        dp[i][j] = dp[i][j-2];// skip char like ,a*
                    } else {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    }
                }
            }
        }

        return dp[s.length()][p.length()];

    }
};
