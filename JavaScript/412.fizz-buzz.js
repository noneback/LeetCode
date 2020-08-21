/*
 * @lc app=leetcode.cn id=412 lang=javascript
 *
 * [412] Fizz Buzz
 */

// @lc code=start
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
  let ret = new Array();
  if (n === 0) return ret;
  let t = 3,
    f = 5,
    i = 1;
  while (i <= n) {
    t--;
    f--;
    if (t === 0 && f === 0) ret.push('FizzBuzz');
    else if (t === 0 && f !== 0) ret.push('Fizz');
    else if (t !== 0 && f === 0) ret.push('Buzz');
    else ret.push(i.toString());

    t = t === 0 ? 3 : t;
    f = f === 0 ? 5 : f;
    i++;
  }
  return ret;
};
// @lc code=end
