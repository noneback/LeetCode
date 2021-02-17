/**
	哈希表 + 排序
**/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (int i = 0;i < nums.size();i++) {
            m[nums[i]]++;
        }
        vector<pair<int,int>> vec{m.begin(),m.end()};

        sort(vec.begin(),vec.end(),[](const pair<int,int> &p1,const pair<int,int> &p2) {
            return p1.second > p2.second;
        });

        vector<int> res;
        for (int i = 0;i < k;i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};
