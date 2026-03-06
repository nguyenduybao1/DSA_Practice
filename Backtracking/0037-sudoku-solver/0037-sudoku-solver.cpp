/*
Leetcode 37 - Sudoku Solver
Pattern: Backtracking + DFS

Idea:
- Preprocess the board and mark existing numbers in row/col/box arrays.
- For each empty cell '.', try numbers 1–9.
- If the number is not used in the row/col/box -> place it.
- Recurse to solve the remaining board.
- If recursion fails -> backtrack (reset the cell).
- If no empty cells remain -> puzzle solved.

Time Complexity: O(9^m) m = number of empty cells
Space Complexity: O(m) recursion stack
*/
class Solution {
private:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.'){

                    for(int num = 1; num <= 9; num++){

                        int b = (i/3)*3 + j/3;

                        if(!row[i][num] && !col[j][num] && !box[b][num]){

                            board[i][j] = num + '0';

                            row[i][num] = true;
                            col[j][num] = true;
                            box[b][num] = true;

                            if(solve(board))
                                return true;

                            board[i][j] = '.';

                            row[i][num] = false;
                            col[j][num] = false;
                            box[b][num] = false;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] != '.'){

                    int num = board[i][j] - '0';
                    int b = (i/3)*3 + j/3;

                    row[i][num] = true;
                    col[j][num] = true;
                    box[b][num] = true;
                }
            }
        }

        solve(board);
    }
};