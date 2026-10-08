#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] stores the maximum jumps to reach index i from index 0
        vector<int> dp(n, -1);
        
        // Base case: Starting point takes 0 jumps
        dp[0] = 0;
        
        // Iterate through each index to calculate maximum jumps
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // We can only jump from j if j itself is reachable
                if (dp[j] != -1) {
                    // Check if the jump condition is satisfied
                    if (abs((long long)nums[i] - nums[j]) <= target) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
