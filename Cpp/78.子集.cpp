class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0;i <= nums.size();i++) {
            vector<int> ans;
            backTrace(nums,i,0,ans);
        }
        return ret;
    }

    void backTrace(vector<int> &nums,int curLen,int index,vector<int> &ans) {
        if (ans.size() ==  curLen ) {
            ret.push_back(ans);
            return;
        }

        if (index == nums.size()) return ;

        for (int i = index ;i < nums.size();i++) {
            ans.push_back(nums[i]);
            backTrace(nums,curLen,i + 1,ans);
            ans.pop_back();
        }
        return ;
    }
};


// 更好理解的版本
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0;i <= nums.size();i++) {
            vector<int> ans;
            backTrace(nums,i,0,ans);
        }
        return ret;
    }

    void backTrace(vector<int> &nums,int curLen,int index,vector<int> &ans) {
        if (ans.size() ==  curLen ) {
            ret.push_back(ans);
            return;
        }

        if (index == nums.size()) return ;
        // 选择当前节点
        ans.push_back(nums[index]);
        backTrace(nums,curLen,index + 1,ans);
        ans.pop_back();
        // 不选择当前节点
        backTrace(nums,curLen,index + 1,ans);
        return ;
    }
};
