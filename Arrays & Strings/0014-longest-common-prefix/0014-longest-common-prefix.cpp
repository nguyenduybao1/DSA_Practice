/*
LeetCode 14 - Longest Common Prefix
Pattern: String Traversal / Vertical Scanning

Idea:
- Use the first string as a reference
- Traverse characters index by index (vertical scanning):
  - At each index i, take character c = strs[0][i]
  - Compare c with the character at index i of all other strings
  - If any string:
    - is shorter than i
    - or has a different character
    → stop and return prefix [0, i)
- If all characters match until the end of the first string,
  return the entire first string



Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
    /* if (strs.empty()) return "";  
    Required only if input strs.length = 0 (not needed for this problem's constraints) 
    NOTE TO SELF: remember to add this check in problems where input array can be empty.
    */

    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

};