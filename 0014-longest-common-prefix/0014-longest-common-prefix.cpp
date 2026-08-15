class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(), str.end());

        string first = str[0];
        string last = str.back();
        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        return str[0].substr(0, i);
    }
};
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        sort(s.begin(), s.end());

        int i = 0;

        while (i < s[0].length() && s[0][i] == s[s.size()-1][i]) {
            ans += s[0][i];
            i++;
        }

        return ans;
    }
};

-----------------------------------------------
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";

        for (int i = 0; i < s[0].length(); i++) {
            for (int j = 0; j < s.size()-1; j++) {

                if (s[j][i] != s[j+1][i])
                    return ans;
            }

            ans += s[0][i];
        }

        return ans;
    }
};
*/