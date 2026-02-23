/*
Leetcode 401 - Binary Watch
Pattern: Bit Manipulation / Brute Force

Idea:
- A binary watch has 4 bits for hours (0-11) and 6 bits for minutes (0-59).
- Brute force all valid combinations: h from 0-11, m from 0-59.
- Use __builtin_popcount() to count the number of set bits in h and m.
- If total set bits == num, it's a valid time, append to result.
- Remember to format minutes: pad with "0" if m < 10.

Time Complexity: O(1)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == num) {
                ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
        }
    }
    return ans;
    }
};