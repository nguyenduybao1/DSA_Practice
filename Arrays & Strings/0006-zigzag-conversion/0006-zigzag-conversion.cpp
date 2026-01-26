/*
Leetcode 6 - Zigzag converion
Pattern: Simulation / String building

Idea:
- Create numRows strings.
- Traverse the string and append chars to rows.
- Move down and up between rows like zigzag.
- Finally concatenate all rows.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = true;

        for(char c : s){
            rows[curRow] += c;

            if(curRow == 0){
                goingDown = true;
            }
            else if(curRow == numRows - 1){
                goingDown = false;
            }
            curRow += goingDown ? 1 : -1;
        }

        string res;
        for(auto& row : rows){
            res += row;
        }
        return res;
    }
};