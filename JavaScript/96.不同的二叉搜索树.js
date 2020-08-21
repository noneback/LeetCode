/*
 * @lc app=leetcode.cn id=96 lang=javascript
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    let arr = new Array()
    arr.push(1);
    arr.push(1);
    arr.push(2);

    for (let i = 3; i < n + 1; i++) {
        let sum = 0;
        for (let j = 0; j < i; j++) {
            sum += arr[j] * arr[i - j - 1];
        }
        arr.push(sum);
    }

    return arr[n];
};

// @lc code=end