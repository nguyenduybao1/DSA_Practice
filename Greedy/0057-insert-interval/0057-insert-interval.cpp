/*
Leetcode 57 - Insert Interval
Pattern: Greedy + Interval Scanning

Idea:
- Because intervals are already sorted and non-overlapping:
  1. Add all intervals completely BEFORE newInterval.
  2. Merge all intervals that OVERLAP with newInterval.
  3. Add all intervals AFTER newInterval.

Key:
- Only overlapping part needs merging.
- No need to sort again.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};