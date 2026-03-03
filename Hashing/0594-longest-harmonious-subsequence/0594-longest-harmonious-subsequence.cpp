/*
Leetcode 594 - Longest Harmonious Subsequence
Pattern: Hash Map / Frequency Count

Idea:
- A harmonious subsequence requires exactly 2 distinct values
  where max - min = 1, so we only care about pairs (x, x+1).
- Count frequency of each number using a hash map.
- For each x in map, if x+1 also exists -> candidate = freq[x] + freq[x+1].
- Track the maximum candidate across all x.

Example: nums = [1,3,2,2,5,2,3,7]
  freq = {1:1, 3:2, 2:3, 5:1, 7:1}
  x=1: freq has 2 → ans = max(0, 1+3) = 4
  x=3: freq has 4? No → skip
  x=2: freq has 3 → ans = max(4, 3+2) = 5  ✓
  x=5: freq has 6? No → skip

Time Complexity: O(n) 
Space Complexity: O(n)
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        int ans = 0;
        for(auto &[x, cnt] : freq){
            if(freq.count(x + 1)){
                ans = max(ans, cnt + freq[x+1]);
            }
        }
        return ans;
    }
};