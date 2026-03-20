/*
Leetcode 55 - Jump Game
Pattern: Greedy

Idea:
- Track the farthest index reachable at each step.
- If we reach a 0 and i >= farthest -> stuck, return false.
- If we never get stuck -> return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for(int i = 0; i < n - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if( i >= farthest && nums[i] == 0){
                return false;
            }
        }
        return true;
    }
};