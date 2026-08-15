class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count = 0;
        for (auto i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(s[i]);
                count = max(count, (int)st.size());
            } else if (s[i] == ')') {
                st.pop();
            }
        }
        return count;
    }
};