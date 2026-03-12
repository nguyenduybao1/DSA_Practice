/*
Leetcode 724 - Find Pivot Index
Pattern: Prefix Sum

Idea:
- Compute total sum of the array.
- For each index i, rightSum = total - leftSum - nums[i].
- If leftSum == rightSum -> found pivot, return i.
- Otherwise, add nums[i] to leftSum and continue.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for(int n : nums){
            total += n;
        }
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++){
            int rightSum = total - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};