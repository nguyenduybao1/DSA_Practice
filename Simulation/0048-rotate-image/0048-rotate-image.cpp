/*
Leetcode 48 - Rotate image
Pattern: Matrix Manipulation 

Idea:
- Rotate the matrix 90 degrees clockwise in-place by:
1. Transposing the matrix (swap matrix[i][j] with matrix[j][i])
2. Reversing each row


Time Complexity: O(n²)
Space Complexity: O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};