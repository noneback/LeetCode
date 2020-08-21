/*
 * @lc app=leetcode.cn id=509 lang=javascript
 *
 * [509] 斐波那契数
 */

// @lc code=start
/**
 * @param {number} N
 * @return {number}
 */
var fib = function (N) {
    let db = new Array();
    db[0] = 0; db[1] = 1;
    for (let i = 2; i <= N; i++)
        db[i] = db[i - 1] + db[i - 2];

    return db[N];

};
// @lc code=end

