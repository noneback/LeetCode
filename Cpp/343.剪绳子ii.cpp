/**
 * 将N尽可能的拆分为多个3，但最后只剩1的时候，
 * 需要将1和3拆分成2*2，因为2*2 > 1*3，故而循环的条件是n > 4.
 */

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;

        long res = 1;
        
        // 理解这一步
        while (n > 4) {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }

        res *= n;
        res %= 1000000007;
        return (int)res;
    }
};
