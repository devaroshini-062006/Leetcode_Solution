#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number in its correct bucket/index if possible
        for (int i = 0; i < n; i++) {
            // While nums[i] is in the valid range [1, n] and not at its correct index (nums[i] - 1)
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index that doesn't match its expected value
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If 1 to n are all present, the missing positive is n + 1
        return n + 1;
    }
};
