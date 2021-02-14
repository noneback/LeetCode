/**
	双指针
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int m[3];
        int ret = 0;
        memset(m,0,sizeof(m));
        int len = s.length();
        if (len < 3) return ret;

        int l = 0, r = 0;

        for (;r < len;r++) {
            m[s[r] - 'a']++;
            while (m[0] && m[1] && m[2]) {
                ret += len - r;
                m[s[l++] - 'a']--;
            }
        }

        return ret;
    }
};
