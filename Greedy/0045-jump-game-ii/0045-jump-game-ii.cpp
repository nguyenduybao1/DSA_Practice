/*
Leetcode 45 - Jump Game II
Pattern: Greedy

Idea:
- Track farthest reachable index and end of current jump range.
- When i reaches end -> must jump, count++ and update end = farthest.
- Stop at n - 1 (no need to jump from last index).

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int farthest = 0;
        int end = 0;
        for(int i = 0; i < n - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == end){
                count++;
                end = farthest;
            }
        }
        return count;
    }
};