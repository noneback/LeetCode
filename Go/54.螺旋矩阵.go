/*
 * @lc app=leetcode.cn id=54 lang=golang
 *
 * [54] 螺旋矩阵
 */

package main

// @lc code=start
func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}

	l, r, t, b := 0, len(matrix[0])-1, 0, len(matrix)-1
	cnt := 0
	ret := make([]int, (r+1)*(b+1))

	for {
		for i := l; i <= r; i++ {
			ret[cnt] = matrix[t][i]
			cnt++
		}
		t++
		if t > b {
			break
		}

		for i := t; i <= b; i++ {
			ret[cnt] = matrix[i][r]
			cnt++
		}
		r--
		if l > r {
			break
		}

		for i := r; i >= l; i-- {
			ret[cnt] = matrix[b][i]
		}
		b--
		if t > b {
			break
		}

		for i := b; i >= t; i++ {
			ret[cnt] = matrix[i][l]
			cnt++
		}

		l++
		if l > r {
			break
		}
	}
	return ret

}

// @lc code=end
