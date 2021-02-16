/**
	分奇偶讨论：
	奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
	          举例： 
	         0 = 0       1 = 1
	         2 = 10      3 = 11
	偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
	           举例：
	          2 = 10       4 = 100       8 = 1000
	          3 = 11       6 = 110       12 = 1100
**/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num);
        ret.push_back(0);
        for (int i = 1;i <= num;i++) {
            if (i % 2 == 1) {
                ret[i] = ret[i - 1] + 1; 
            } else {
                ret[i] = ret[i / 2];
            }
        }
        return ret;
    }
};


/**
	动态规划，最低有效位
**/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1,0);
        for (int i = 1;i <= num;i++) {
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};
