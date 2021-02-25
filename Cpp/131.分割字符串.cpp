/**
	回溯
**/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tracer;
        vector<vector<string>> ans;
        backtrace(s,tracer,ans,0,s.length() - 1);
        return ans;
    }

    void backtrace(string &s,vector<string> &tracer,vector<vector<string>> &ans,int l, int r) {
        if (l > r){
            ans.push_back(tracer);
            return ;
        }
        for (int i = 1;i <= r - l + 1 ;i++) {
            //从index为l开始截取长度为1,2,3...的子串进行验证，成功则用剩下的部分递归。
            if (isIt(s,l,l + i - 1)) {
                tracer.push_back(s.substr(l,i));
                backtrace(s,tracer,ans,l + i,r);
                tracer.pop_back();
            } 
        }
    }

    bool isIt(string &s,int l,int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
