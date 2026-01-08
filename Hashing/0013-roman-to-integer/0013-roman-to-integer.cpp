/*
Leetcode 13 - Roman to Integer
Pattern: Hashing

Idea:
- Map each Roman character to its integer value
- Traverse the string from left to right
- If current value < next value, subtract it
- Otherwise, add it

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
                result -= mp[s[i]];
            } else {
                result += mp[s[i]];
            }
        }
        return result;
    }
};
