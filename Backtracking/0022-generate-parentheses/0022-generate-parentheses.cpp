/*
Leetcode 22 - Generate Parenthesis
Pattern: Backtracking(DFS)

Idea:
- Use backtracking to generate parentheses
- Try adding '(' if open < n
- Try adding ')' if close < open
- When length == 2*n, add to result

Time Complexity: O(4^n / sqrt(n))
Space Complexity: O(n)
*/
class Solution {
public:
    vector<string> res;
    void backtrack(string path, int open, int close, int n){
        if(path.size() == 2 * n){
            res.push_back(path);
            return;
        }

        if(open < n){
            backtrack(path + "(", open + 1, close, n);
        }

        
        if(close < open){
            backtrack(path + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
      backtrack("", 0, 0, n);
      return res;
    }
};