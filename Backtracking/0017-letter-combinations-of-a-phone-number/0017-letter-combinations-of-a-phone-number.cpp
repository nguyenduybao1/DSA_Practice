/*
Leetcode 17 - Letter Combinations of a Phone Number
Pattern: Backtracking(DFS) + Hashing

Idea:
- Map each digit to letters
- Use backtracking to build the string step by step.
- When current length == digits length -> push to result.

Time Complexity: O(4^n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        string path;

        backtrack(0, digits, mp, path, res);
        return res;
    }
private:
    void backtrack(int idx, string& digits, 
                   unordered_map<char, string>& mp, 
                   string& path, vector<string>& res){
        if(idx == digits.size()){
            res.push_back(path);
            return;
        }

        for(char c : mp[digits[idx]]){
            path.push_back(c);
            backtrack(idx + 1, digits, mp, path, res);
            path.pop_back();
        }
    }
};