class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        bool flag[nums.size()];
        memset(flag,false,sizeof(flag));

        for (auto x : nums) {
            flag[x-1] = true;
        }

        for (int i = 0;i < nums.size();i++) {
            if (!flag[i]) ret.push_back(i+1);
        }

        return ret;
    }
};
