/**
错位相减法，注意整数溢出的问题
**/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() <= 1) return 0;
        vector<int> relative;
        int len = A.size();
        long sum = 0;
        int max = INT_MIN;
        for (int i = 0;i < A.size();i++) sum += A[i];

        for (int i = 0;i < A.size();i++) {
            long total = 0;
            if (relative.size() == 0){
                for (int j = 0;j < A.size();j++) {
                    total += j * A[j];       
                }
            } else {
                total = relative[i-1] + sum -(long) len * A[len - i];
            }
            relative.push_back(total);
            max = max > total ? max : total;
            
        }
        return max;
    }
};
