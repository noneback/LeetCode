/*
 * @lc app=leetcode.cn id=48 lang=javascript
 *
 * [48] 旋转图像
 */

// @lc code=start
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
  let temp;
  let n = matrix.length;
  for (let i = 0; i < Math.floor(n / 2); i++) {
    for (let j = i; j < n - 1 - i; j++) {
      temp = matrix[i][j];
      let x = i;
      let y = j;
      let t;
      for (let k = 0; k < 4; k++) {
        let t = matrix[y][n - 1 - x];
        let t_x = x;
        x = y;
        y = n - 1 - t_x;
        t = matrix[x][y];
        matrix[x][y] = temp;
        temp = t;
      }
    }
  }
};
// @lc code=end
