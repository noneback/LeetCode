/**

题目的核心在于如何去检测循环，一般有两种方法,快慢指针，或者使用集合。
*/



class Solution {
public:

    int getNext(int n) {
        int ret = 0;
        while (n > 0) {
            int num = n % 10;
            ret +=  num * num; 
            n /= 10;
        } 
        return ret;
    }
    bool isHappy(int n) {
        int faster = getNext(n),slower = n;

        while (faster != 1 && faster != slower) {
            slower = getNext(slower);
            faster = getNext(getNext(faster));
        }
        return faster == 1;
    }
};
