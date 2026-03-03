/*
Leetcode 3 - Longest Substring Without Repeating Characters
Pattern: Sliding Window / Hash Set / TwoPointers

Idea:
- Use a sliding window with two pointers (left, right).
- Expand window by moving right, insert s[right] into the set.
- If s[right] already exists in set -> shrink window from left
  until the duplicate is removed.
- Track max window size at each step.

Time Complexity: O(n)
Space Complexity: O(min(n, m)) - m is charset size (26 for lowercase)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            while(st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};