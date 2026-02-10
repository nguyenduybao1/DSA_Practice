/*
Leetcode 119 - Pascal's Triangle II
Pattern: Dynamic Programming

Idea:
- Use a 1D array to build the row.
- dp[j] represents the value at current row, position j.
- Initialize dp[0] = 1.
- For each row i:
  - Update dp from right to left:
    dp[j] = dp[j] + dp[j - 1]
- Right-to-left update avoids overwriting previous values.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp;
    }
};
