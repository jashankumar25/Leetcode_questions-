class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        
        int max_diff = 0;
        vector<long long> diff_count(100005, 0);
        
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diff_count[d]++;
            max_diff = max(max_diff, d);
        }
        
        for (int i = max_diff; i > 0; --i) {
            if (diff_count[i] == 0) continue;
            
            long long operations = min(totalK, diff_count[i]);
            diff_count[i] -= operations;
            diff_count[i - 1] += operations;
            totalK -= operations;
            
            if (totalK == 0) break;
        }
        
        long long min_sum_sq_diff = 0;
        for (int i = 1; i <= max_diff; ++i) {
            if (diff_count[i] > 0) {
                min_sum_sq_diff += diff_count[i] * (long long)i * i;
            }
        }
        
        return min_sum_sq_diff;
    }
};