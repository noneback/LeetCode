class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string beg;
        backTrace(ret,0,beg,n,0,0);
        return ret;
        
    }

    void backTrace(vector<string> &ret,int index,string str,int n,int l,int r) {
        if (index == 2 * n) {
            ret.push_back(str);
            return ;
        }

        string lr[2]{str + '(',str + ')'};

        if (isFit(l + 1,r,n)) backTrace(ret,index + 1,lr[0],n,l + 1,r);
        if (isFit(l,r + 1,n)) backTrace(ret,index + 1,lr[1],n,l,r + 1);
    }

    bool isFit(int l,int r,int n) {
        return l >= r && l <=n && r <= n;
    }
};
