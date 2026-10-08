#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        // Step 1: Build the prefix maximum array
        vector<int> preMax(n);
        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }
        
        // Step 2: Iterate backward to evaluate cross-boundary connections
        int sufMin = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            if (preMax[i] > sufMin) {
                // If the prefix max is greater than a future suffix min, 
                // we can bridge to the next segment's maximum.
                ans[i] = ans[i + 1];
            } else {
                // Otherwise, we cannot jump past this point, so our limit is the prefix max.
                ans[i] = preMax[i];
            }
            // Update the suffix minimum seen so far
            sufMin = min(sufMin, nums[i]);
        }
        
        return ans;
    }
};
