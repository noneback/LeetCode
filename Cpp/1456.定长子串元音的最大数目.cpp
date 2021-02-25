/**
	滑动窗口
**/

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, tmp = 0;
        int l = 0, r = k;
        for (int i = 0;i < k;i++) {
            tmp += isVowel(s[i]);
            ans = max(tmp,ans);
        }

        while (r < s.length()) {
            tmp -= isVowel(s[l++]);
            tmp += isVowel(s[r++]);
            ans = max(tmp,ans);
        }
        return ans;

    }

    int isVowel (char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 1;
        }
        return 0;
    }
};
