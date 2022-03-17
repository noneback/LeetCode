class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; ++i) {
            ans.push_back(i ^ (i >> 1));  // G(i) = i ^ (i / 2);
        }
        return ans;
    }   
};
