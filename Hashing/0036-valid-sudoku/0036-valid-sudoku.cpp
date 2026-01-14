/*
Leetcode 36 - Valid Sudoku
Pattern: Hashing

Idea:
- Use sets to track numbers seen in each row,col and 3x3 box.
- If any number appears more than once in the same row,col or box. 
   Return false
- Otherwise, the board is valid.

Time Complexity: O(n)
Space Complexity: O(n)
*/

lass Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;

            for(int j = 0; j < 9; j++){

                if(board[i][j] != '.'){
                    if(row.count(board[i][j])){
                        return false;
                    }
                    row.insert(board[i][j]);
                }

                if(board[j][i] != '.'){
                    if(col.count(board[j][i])){
                        return false;
                    }
                    col.insert(board[j][i]);
                }

                int r = 3 * (i/3) + j/3;
                int c = 3 * (i%3) + j%3;
                if(board[r][c] != '.'){
                    if(box.count(board[r][c])){
                        return false;
                    }
                    box.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};