class Solution {
public:
    const int overflow = 2147483647;

    int divide(int dividend, int divisor) {
        bool is_positive = (divisor > 0 && dividend > 0 || dividend < 0 && divisor < 0);
        long _divisor = abs(divisor);
        long _dividend = abs(dividend);
        long cnt = 0;
        long origin_divisor = _divisor;
        long times = 1;

        while (_dividend >= origin_divisor) {
            // 指数下降，防止超时
            if (_dividend >= _divisor) {
                _dividend -= _divisor;
                cnt += times;
                _divisor = _divisor << 1;
                times = times << 1;
            } else {
                _divisor = _divisor >> 1;
                if (_divisor < origin_divisor) {
                    return cnt;
                }
                times = times >> 1;
            }

            if (cnt > INT_MAX && is_positive) {
                return overflow;
            }            
        }

        return static_cast<int>(is_positive ? cnt : -cnt);
    }
};
