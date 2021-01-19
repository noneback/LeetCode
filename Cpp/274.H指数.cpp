// H指数排序后，保证序号小于引用数

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 0;
        for (;i < citations.size();i++) {
            if (i+1 > citations[i]) return i;
        }
        return i;

    }
};
