/*
Leetcode 67 - Add Binary
Pattern: TwoPointers

Idea:
- Simulate binary addition from right to left using two pointers.
- At each step, add the current bits and the carry, store the result bit, and update the carry.
- Continue until both strings are processed and there is no remaining carry.

Time Complexity: O(max(n,m))
Space Complexity: O(max(n,m))
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans ="";
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            
            if(i >= 0){
                sum += a[i--] - '0';
            }
            if(j >= 0){
                sum += b[j--] - '0';
            }

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};