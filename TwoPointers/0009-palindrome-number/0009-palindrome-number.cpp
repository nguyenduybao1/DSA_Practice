/*
Leetcode 9 - Palindrome Number
Pattern: Reversed Number

Idea:
- A palindrome number reads the same forward and backward
- Negative numbers and numbers ending with 0 (except 0) are not palindromes
- Reverse only half of the number to avoid OVERFLOW
- Stop when reversed >= remaining number
- For even digits: x == reversed
- For odd digits: x == reversed / 10

Time Complexity: O(log10(x))
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || (x % 10 == 0 && x != 0)){
        return false;
       }

       int reversed = 0;
       while(x > reversed){
            reversed = reversed * 10 + x % 10;
            x /= 10;
       }
       return reversed == x || x == reversed / 10 ;
    }
};
