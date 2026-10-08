#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to track the position of valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not the value to remove
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k; // k is the number of elements not equal to val
    }
};
