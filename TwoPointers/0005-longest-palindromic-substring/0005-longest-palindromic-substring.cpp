/*
Leetcode 5 - Longest Palindromic Substring
Pattern: TwoPointers(Expand Around Center)

Idea:
- For each index, expand from the center.
- Check both odd and even length palindromes.
- Expand while characters match.
- Track the longest substring.

Time Complexity: O(n²)
Space Complexity: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        
        int start = 0, maxLen = 1;
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i, start, maxLen);
            expand(s, i, i+1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

    void expand(string& s, int left, int right, int& start, int& maxLen){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        int len = right - left - 1;

        if(len > maxLen){
            maxLen = len;
            start = left + 1;
        }
    }
};