class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> container;
        BackTrack(candidates, container, 0, target, 0);
        vector<vector<int>> ret {s.begin(), s.end()};
        return ret;
    }

    void BackTrack(const vector<int> &arr, vector<int> &v, int i, int target, int begin) {
        if (target == 0) {
            s.insert(v);
            return;
        }
        while (i != begin && i < arr.size() && arr[i - 1] == arr[i]) i++;

        if (i == arr.size() || target < arr[i]) return; // no need to go down

        v.push_back(arr[i]);
        BackTrack(arr, v, i + 1, target - arr[i], i + 1);
        v.pop_back();
        BackTrack(arr, v, i + 1, target, begin);
    }
};
