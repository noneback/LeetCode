/**
动态规划 或者 利用stack匹配括号

见(题解)[https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-si-lu-xiang-jie-c-by-zhanganan042/]
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length() + 1];
        memset(dp,0,sizeof(dp));
        int maxV = 0;

        for (int i = 1;i < s.length();i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = 2;
                    if (i >= 2) dp[i] += dp[i-2];
                } else if (dp[i - 1] > 0) {
                    if ((i - dp[i-1] - 1)>= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((i - dp[i - 1] - 2) >= 0) dp[i] = dp[i] + dp[i - dp[i - 1] - 2]; 
                    }
                }
                maxV = max(maxV,dp[i]);
            }
        }
        return maxV;
    }
};


// stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxV = 0;
        stk.push(-1);
        for (int i = 0;i < s.length();i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else maxV = max(maxV,i - stk.top());
            }
        }
   

        return maxV;


    }
};
