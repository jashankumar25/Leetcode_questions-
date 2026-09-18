class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int left = 0;
        vector<int> ans;

        int freq[51] = {0};

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] < 0) {
                freq[-nums[right]]++;
            }

            if (right - left + 1 == k) {

                int count = 0;
                int beauty = 0;

                for (int i = 50; i >= 1; i--) {

                    count += freq[i];

                    if (count >= x) {
                        beauty = -i;
                        break;
                    }
                }

                ans.push_back(beauty);

                if (nums[left] < 0) {
                    freq[-nums[left]]--;
                }

                left++;
            }
        }

        return ans;
    }
};