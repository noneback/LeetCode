/**
	use stack to match
*/

class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string tmp;
        stack<int> num_stk;
        stack<string> str_stk;

        for (char c : s) {
            if (isdigit(c)) num = num * 10 + c - '0';
            else if (c == '[') {
                num_stk.push(num);
                num = 0;
                str_stk.push(tmp);
                tmp = "";
            } else if (c == ']') {
                int num = num_stk.top();
                num_stk.pop();

                string str = "";
                for (int i = 0;i < num;i++) str += tmp;
                string last = str_stk.top(); // store single char
                str_stk.pop();
                tmp = last + str;
            } else {
                // c is a alpha
                tmp.push_back(c);
            }

        }
        return tmp;
    }
};
