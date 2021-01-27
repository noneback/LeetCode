/**
计算阶乘的末尾零的个数可以转换为求阶乘因子分解质因式后`5*2`的总对数,
由于`5`的个数一定比`2`的个数要少，所以 只需要求`5`作为因子的个数即可
注意有的数可以拆分成两个5,如`25 = 5 * 5`
所以代码可以等价为如下代码
*/


class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n > 0) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};
