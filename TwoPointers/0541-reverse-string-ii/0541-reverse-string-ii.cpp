/*
Leetcode 541 - Reverse String II 
Pattern: Two Pointers (Chunk-based Reversal)

Idea:
- Traverse the string in steps of size 2k
- For each 2k block, reverse the first k characters
- Use two pointers to reverse characters in-place within each k segment
- Leave the remaining characters unchanged

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for( int i = 0;  i < n; i += 2 * k ){
            int left = i;
            int right = min(i + k - 1, n - 1 );
            while( left < right ){
                swap(s[left], s[right]);
                left++;
                right--;
            }
        } 
        return s;
    }
};