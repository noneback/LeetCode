class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> v(num1.length() + num2.length(), 0);

        for (int i = 0;i < num2.length();++i) {
            int mulor = num2[num2.length() - 1 - i] - '0';
            for (int j = 0;j < num1.length();++j) {
                // 计算单位乘法
                int mulee = num1[num1.length() - 1 - j] - '0';
                v[j + i] += mulee * mulor;
            }
        }
        int ac = 0;
        char val;
        string ans;
        for (int i = 0;i < v.size();i++) {
            int mid_val = v[i] + ac;
            ac = mid_val / 10;
            val = '0' + mid_val % 10;
            ans = val + ans;
        }
        int k = 0;
        while (ans[k] == '0') k++; // 去除前导0
        
        return ans.length() - k != 0 ? ans.substr(k, ans.length() - k) : "0";
    }
};
