#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        std::sort(arr.begin(), arr.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });
        
        std::vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
        
        return swaps;
    }
};