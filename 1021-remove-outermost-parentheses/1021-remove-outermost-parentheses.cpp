class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int counter = 0;
        for (char ch : s) {

            if (ch == ')') {
                counter--;
            }

            if (counter != 0) {
                ans.push_back(ch);
            }
            if (ch == '(') {
                counter++;
            }
        }
        return ans;
    }
};
/*string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) {
                    ans += ch;
                }

                depth++;
            } else {
                depth--;

                if (depth > 0)
                    ans += ch;
            }
        }
        return ans;
    }
------------------------------------------------------
string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                if (!st.empty()) {
                    ans = ans + ch;
                }
                st.push(ch);
            } else {
                st.pop();

                if (!st.empty()) {
                    ans += ch;
                }
            }
        }
        return ans;
    }*/