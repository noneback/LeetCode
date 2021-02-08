class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(),intervals.end(),[](const vector<int>& in1,const vector<int>& in2){
            return in1[0] < in2[0];
        });

        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1;i < intervals.size();i++) {
            auto nextIn = intervals[i];
            if (r >= nextIn[0]) {
                r = max(r, nextIn[1]);
            } else {
                vector<int> ans{l,r};
                ret.push_back(ans);
                l = nextIn[0];
                r = nextIn[1];
            }
            if (i + 1 >= intervals.size()) {
                vector<int> ans{l,r};
                ret.push_back(ans);
            }
        }
        return ret;


    }
};
