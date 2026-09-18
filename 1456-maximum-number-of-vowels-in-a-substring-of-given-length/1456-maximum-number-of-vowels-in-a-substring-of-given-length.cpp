class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0;
        int ans = 0;
        int maxvowel = 0;

        for (auto right = 0; right < s.length(); right++) {
            if (isvowel(s[right])) {
                ans++;
            }
            if (right - left + 1 == k) {
                maxvowel = max(maxvowel, ans);
                if (isvowel(s[left]))
                    ans--;

                left++;
            }
        }
        return maxvowel;
    }
};