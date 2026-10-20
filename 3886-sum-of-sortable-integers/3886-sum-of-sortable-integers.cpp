#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find all divisors of n efficiently in O(sqrt(n)) time
        std::vector<int> fac;
        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }
        
        // Step 2: Get the sorted target array
        std::vector<int> target = nums;
        std::ranges::sort(target);
        
        // KMP helper function to check if nums2 is a cyclic rotation of nums1
        auto kmp_check = [](const std::vector<int>& nums1, const std::vector<int>& nums2) {
            int L = nums1.size();
            // Concatenate nums1 with itself to contain all cyclic rotations
            std::vector<int> extended = nums1;
            extended.insert(extended.end(), nums1.begin(), nums1.end());
            
            // Standard KMP substring search of nums2 inside extended
            int m = nums2.size();
            std::vector<int> pi(m, 0);
            int j = 0;
            for (int i = 1; i < m; ++i) {
                while (j > 0 && nums2[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums2[i] == nums2[j]) {
                    ++j;
                }
                pi[i] = j;
            }
            
            j = 0;
            for (int i = 0; i < extended.size(); ++i) {
                while (j > 0 && extended[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (extended[i] == nums2[j]) {
                    ++j;
                }
                if (j == m) {
                    return true; // Found a matching cyclic shift
                }
            }
            return false;
        };
        
        long long total_sum = 0;
        
        // Step 3: Check each divisor k
        for (int k : fac) {
            bool possible = true;
            for (int i = 0; i < n; i += k) {
                std::vector<int> sub_nums(nums.begin() + i, nums.begin() + i + k);
                std::vector<int> sub_target(target.begin() + i, target.begin() + i + k);
                
                if (!kmp_check(sub_nums, sub_target)) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};