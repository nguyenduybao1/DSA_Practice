/*
Leetcode 118 - Pascal's Triangle
Pattern: Dynamic Programming

Idea:
- Each row starts and ends with 1.
- Inner elements are the sum of two elements from the previous row:
  triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
- Build the triangle row by row from top to bottom.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;

        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; j++){
                row[j] = dp[i-1][j-1] + dp[i-1][j];
            }
            dp.push_back(row);
        }
        return dp;
    }
};