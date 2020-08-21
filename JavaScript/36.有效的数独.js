/*
 * @lc app=leetcode.cn id=36 lang=javascript
 *
 * [36] 有效的数独
 */

// @lc code=start
/**
 * @param {character[][]} board
 * @return {boolean}
 */

var isValidSudoku = function (board) {
  let rows = board.map(t => new Set());
  let cols = board.map(t => new Set());
  let nines = board.map(t => new Set());

  for (let i in board) {
    for (let j in board[i]) {
      if (board[i][j] !== '.') {
        let value = board[i][j];
        let nine_num = Math.floor(i / 3) * 3 + Math.floor(j / 3);
        if (
          rows[i].has(value) ||
          cols[j].has(value) ||
          nines[nine_num].has(value)
        )
          return false;
        else {
          rows[i].add(value);
          cols[j].add(value);
          nines[nine_num].add(value);
        }
      }
    }
  }

  return true;
};
// @lc code=end
