#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int len = nums.size();
        // The base[n] array always has a length of n + 1. 
        // Thus, n must be len - 1.
        int n = len - 1;
        
        // If the array has fewer than 2 elements, it can't even form base[1] = [1, 1]
        if (n < 1) return false;

        // Use a frequency array to count occurrences of each number.
        // Size is n + 1 to safely access up to index 'n'.
        vector<int> counts(n + 1, 0);

        for (int num : nums) {
            // If any number is out of the valid range [1, n], it's invalid
            if (num < 1 || num > n) {
                return false;
            }
            counts[num]++;
        }

        // Check if numbers 1 to n-1 appear exactly once
        for (int i = 1; i < n; ++i) {
            if (counts[i] != 1) {
                return false;
            }
        }

        // Check if the number n appears exactly twice
        return counts[n] == 2;
    }
};
