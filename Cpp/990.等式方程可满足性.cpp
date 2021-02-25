/**
	并查集
**/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,char> hashmap;
        int cnt = 0;

        for (auto str : equations) {
            char l = str[0];
            char r = str[3];
            hashmap[l] = l;
            hashmap[r] = r;
        }

        for (auto str : equations) {
            char l = str[0];
            char r = str[3];
            if (str[1] == '=') {
                equ(l,r,hashmap);
            }
        }
         

        for (auto str : equations) {
            char l = str[0];
            char r = str[3];
            char c1 = findEqu(l,hashmap);
            char c2 = findEqu(r,hashmap);

            if (str[1] == '!') {
                if (c1 == c2) return false;
            } else if (str[1] == '=') {
                if (c1 != c2) return false;
            }
        }
        return true;
        
    }

    char findEqu(char c,unordered_map<char,char> &hashmap) {
        char ch = c;
        while (ch != hashmap[ch]) {
            ch = hashmap[ch];
        }

        while (c != hashmap[c]) {
            char tmp = hashmap[c];
            hashmap[c] = ch;
            c = tmp; 
        }

        return ch;
    }

    void equ(char ch1,char ch2,unordered_map<char,char> &hashmap) {
        char equch1 = findEqu(ch1,hashmap);
        char equch2 = findEqu(ch2,hashmap);
        if (equch1 != equch2) {
             hashmap[equch1] = hashmap[equch2];
        }
    }
};
