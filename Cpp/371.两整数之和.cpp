/**
	结题的要点是位运算。两个数的异或运算可以得到不进位的加法运算结果，与运算可以得到两个数对应位的进位结果
	所以每次的加法需要`进位加法结果 + 进位后的结果`,即 `a ^ b + (a & b) << 1 `,直到无进位产生，计算完成
	
*/


class Solution {
public:
    int getSum(int a, int b) {
        if (!b) return a;
        return getSum(a ^ b,(unsigned)(a & b) << 1);
    }
};
