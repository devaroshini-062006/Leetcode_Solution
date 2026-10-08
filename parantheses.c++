#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int openCount, int closeCount, int maxPairs) {
        if (current.length() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

       
        if (openCount < maxPairs) {
            backtrack(result, current + "(", openCount + 1, closeCount, maxPairs);
        }
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, maxPairs);
        }
    }
};
