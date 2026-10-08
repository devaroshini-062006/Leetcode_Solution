#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store value -> index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement is already present in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution exists (though constraints guarantee one)
        return {};
    }
};
