class Solution {
public:
    string largestOddNumber(string num) {

        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) // odd
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
/*
substr(pos, len);
pos: Index of the first character to be copied.
len: Length of the sub-string.
*/