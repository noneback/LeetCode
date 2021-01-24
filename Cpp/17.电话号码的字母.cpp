class Solution {


public:
    map<char,char> begMap {
        {'1',' '},
        {'2','a'},
        {'3','d'},
        {'4','g'},
        {'5','j'},
        {'6','m'},
        {'7','p'},
        {'8','t'},
        {'9','w'}
    };
    
    vector<string> letterCombinations(string digits){
        vector<string> ret;
        if (digits.length() == 0) return ret;
        ret.push_back("");
        auto ans = genChars(digits,0,ret);
        return ans;
    }

    vector<string> genChars(string &digits,int index,vector<string> ret){
        if (index == digits.size()) return ret;
    
        if (digits[index] < '2' || digits[index] > '9') return genChars(digits,index + 1,ret);
        vector<string> ans;
        char begChar = begMap[digits[index]];
        int upperBound = (begChar == 'p' || begChar == 'w') ? 4 : 3;

        for (int i = 0;i < upperBound;i++) {
            for (auto &str : ret) {
                char ch = begChar + i;
                ans.push_back(str + ch);
            }
        }

        return genChars(digits,index + 1,ans);
    }

};
