/*
Leetcode 344 - Reverse String
Pattern: Two Pointers (In-place Array Reversal)

Idea:
- Initialize two pointers at the beginning and the end of the array
- Swap the characters at the two pointers
- Move the pointers toward each other until they meet

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while( left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};