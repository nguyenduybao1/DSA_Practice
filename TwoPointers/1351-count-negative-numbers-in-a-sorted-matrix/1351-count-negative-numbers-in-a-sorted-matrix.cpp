/*
Leetcode 1351 - Count Negative Numbers in a Sorted Matrix
Pattern: Two Pointers (Matrix TraversalTraversal, Staircase Search)

Idea:
- The matrix is sorted in non-increasing order by rows and columns
- Start from the bottom-left corner
- If the current value is negative, all elements to the right are also negative
  → add (n - col) to the count and move up
- If the current value is non-negative, move right

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int row = m - 1, col = 0;
        int count = 0;

        while (row >= 0 && col < n)
        {
            if (grid[row][col] < 0)
            {
                count += n - col;
                row--;
            }
            else
            {
                col++;
            }
        }
        return count;
    }
};