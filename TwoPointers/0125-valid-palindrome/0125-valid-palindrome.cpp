/*
LeetCode 125 - Valid Palindrome
Pattern: Two Pointers

Idea:
- Use two pointers to check whether the string is a palindrome.
- Initialize one pointer at the start and one at the end of the string
- While left < right:
   - Skip characters that are not letters or digits
   - Convert both characters to lowercase
   - If the characters are not equal, return false
   - Move both pointers inward
 - If all valid characters match, return true



Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};