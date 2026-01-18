/*
Leetcode 58 - Length of last word
Pattern: String Traversal
Idea:
- Scan the string from the end.
- First, skip all trailing spaces.
- Then count characters until we reach a space or the start of the string.
- The count is the length of the last word.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;

        while(i >= 0 && s[i] == ' '){
            i--;
        }

        while(i >= 0 && s[i] != ' '){
            len++;
            i--;
        }

        return len;
    }
};