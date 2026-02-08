/*
Leetcode 56 - Merge Intervals
Pattern: Sorting + Greedy

Idea:
- Sort intervals by start time.
- Iterate through each interval:
  - If no overlap, push to result.
  - If overlap, merge by updating the end time.
- Always merge with the last interval in result.

Key:
- After sorting, overlapping intervals are adjacent.
- Only need to compare with res.back().

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        for (auto &interval : intervals) {
            if (res.empty() || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
