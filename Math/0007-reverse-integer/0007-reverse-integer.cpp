/*
Leetcode 7 - Reverse Integer
Pattern: Math (Digits Manipulation)

Idea:
- We reverse the number by extracting digits one by one.
- In each step, take the last digit using modulo 10, remove it by dividing by 10,
  and append it to the result by multiplying the result by 10 and adding the digit.
- Before updating the result, we check for integer overflow.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10){
                return 0;
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};