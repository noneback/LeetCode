class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int i = 0;
        for (;i < intervals.size() - 1;i++) {
            if (intervals[i][0] > newInterval[0]) {
                break;
            }
        }
        
        int j = intervals.size() - 1;
        while (j > i) {
            intervals[j] = intervals[j - 1];
            j--;
        }
        intervals[i] = newInterval;

        // compact
        vector<vector<int>> ans;
        vector<int> interval{intervals[0]};
        for (int i = 1;i < intervals.size();i++) {
            if (interval[1] < intervals[i][0]) {
                // new interval
                ans.push_back(interval);
                interval = intervals[i];
            } else {
                interval[1] = max(interval[1], intervals[i][1]);
            }
        }
        ans.push_back(interval);
        return ans;
    }
};
