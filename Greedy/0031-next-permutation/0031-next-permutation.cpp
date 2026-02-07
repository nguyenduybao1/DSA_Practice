/*
Leetcode 31 - Next Permutation
Pattern: Greedy - TwoPointers

Idea:
- Traverse from right to left to find first index i where nums[i] < nums[i+1].
  -> This is the pivot (first decreasing point).
- From right to left, find first number > nums[i], swap them.
- Reverse the suffix (i+1 → end) to get the smallest order.

Key:
- Right side is always decreasing.
- Swap + reverse makes the next lexicographical permutation.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};