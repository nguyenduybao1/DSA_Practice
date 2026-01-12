/*
Leetcode 1266 - Minimum Time Visiting All Points
Pattern: Greedy

Idea:
- For each pair of consecutive points, we can move horizontally, vertically,
  or diagonally by 1 unit per second.
- Diagonal moves reduce both x and y distances, so we always take as many
  diagonal moves as possible.
- The minimum time between two points is max(|dx|, |dy|).
- Sum this value for all consecutive point pairs.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size();i++){
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            ans += max(dx, dy);
        }   
        return ans;
    }
};