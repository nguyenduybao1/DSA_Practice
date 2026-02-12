/*
Longest Balanced Substring
Pattern: Brute Force + Frequency Counting

Idea:
- Fix left boundary.
- Expand right boundary and maintain:
    + freq[26] for character frequency
    + distinct = number of distinct characters
    + maxFreq = maximum frequency among characters
    + cntMax = number of characters having frequency == maxFreq
- A substring is "balanced" if:
    distinct == cntMax
  (i.e., all distinct characters appear the same number of times)
- Update maximum length.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        for (int left = 0; left < n; left++) {
            int freq[26] = {0};
            int distinct = 0;
            int maxFreq = 0;
            int cntMax = 0;

            for (int right = left; right < n; right++) {
                int c = s[right] - 'a';
                int f = ++freq[c];

                if (f == 1) distinct++;

                if (f > maxFreq) {
                    maxFreq = f;
                    cntMax = 1;
                } else if (f == maxFreq) {
                    cntMax++;
                }

                if (distinct == cntMax) {
                    ans = max(ans, right - left + 1);
                }
            }
        }
        return ans;
    }
};
