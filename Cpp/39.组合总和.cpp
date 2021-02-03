class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> ans;
        dfs(ret,ans,candidates,target,0);
        return ret;

    }

    void dfs(vector<vector<int>> &ret,vector<int> &ans,const vector<int> &candidates,int target,int index) {
        if (target <= 0 || index == candidates.size()) {
            if (target == 0) ret.push_back(ans);
            return;
        } 

        for (int i = index;i < candidates.size();i++) {
            ans.push_back(candidates[i]);
            dfs(ret,ans,candidates,target - candidates[i],i);
            ans.pop_back();
        }
        return;
    }
};
