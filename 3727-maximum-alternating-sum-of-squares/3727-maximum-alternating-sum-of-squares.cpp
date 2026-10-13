class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        vector<long long> squared(n);

        for (int i = 0; i < nums.size(); i++) {
            long long val = nums[i];
            squared[i] = val * val;
        }
        sort(squared.begin(), squared.end());

        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum -= squared[i];
        }
        for (int i = n/2; i < n; i++) {
            sum += squared[i];
        }

        return sum;
    }
};