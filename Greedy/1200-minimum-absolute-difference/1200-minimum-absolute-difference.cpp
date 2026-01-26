/*
Leetcode 1200 - Minimum absolute difference
Pattern: Sorting - Greedy
Idea:
- Sort the array first.
- The minimum difference must appear between adjacent elements.
- Scan once to find the minimum difference.
- Scan again to collect all pairs with that difference.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }

        vector<vector<int>> result;
        for (int i = 0; i < arr.size() - 1; i++) {
            if(arr[i+1] - arr[i] == minDiff){
                result.push_back({arr[i], arr[i+1]});
            }
        }
    return result;
    }
};