/*
 * @lc app=leetcode.cn id=542 lang=java
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        int[][] ret = new int[row][];
        for (int i = 0; i < row; i++) {
            ret[i] = new int[col];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ret[i][j] = Integer.MAX_VALUE-100000;//防止溢出问题
                
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0)
                    ret[i][j] = 0;
                else {
                    if (i > 0)
                        ret[i][j] = Math.min(ret[i][j], ret[i - 1][j] + 1);
                    if (j > 0)
                        ret[i][j] = Math.min(ret[i][j], ret[i][j - 1] + 1);
                }
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i < row - 1)
                    ret[i][j] = Math.min(ret[i][j], ret[i + 1][j] + 1);
                if (j < col - 1)
                    ret[i][j] = Math.min(ret[i][j], ret[i][j + 1] + 1);
            }
        }

        return ret;

    }
}
// @lc code=end
