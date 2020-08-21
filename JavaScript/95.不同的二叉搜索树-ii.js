/*
 * @lc app=leetcode.cn id=95 lang=javascript
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function (n) {
    if (n === 0) return new Array();
    return generate_trees(1, n);

};

var generate_trees = function (start, end) {
    let trees = new Array();
    if (start > end) {
        trees.push(null);
        return trees;
    }
    for (let i = start; i <= end; i++) {
        let r_trees = generate_trees(i + 1, end);
        let l_trees = generate_trees(start, i - 1);

        for (let r of r_trees) {
            for (let l of l_trees) {
                let t = new TreeNode(i);
                t.left = l;
                t.right = r;
                trees.push(t);
            }
        }

    }

    return trees;
}
    // @lc code=end