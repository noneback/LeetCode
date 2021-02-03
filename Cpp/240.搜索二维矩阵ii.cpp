/**
从左下角开始搜索，维护rows和cols
**/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1, cols = 0;

        while(rows >= 0 && cols < matrix[0].size()) {
            if (matrix[rows][cols] == target) return true;
            else if (matrix[rows][cols] > target) rows--;
            else cols++; 
        }
        return false;

    }
};
