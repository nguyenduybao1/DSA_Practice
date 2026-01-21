/*
Leetcode 283 - Move Zeroes
Pattern: TwoPointers - Slow & Fast Pointers

Idea:
- The goal is to move all zeroes to the end of the array while keeping the relative order of non-zero elements.
- Use Two Pointers:
  - fast (read pointer) to traverse the array.
  - slow (write pointer) to track the position for the next non-zero element.
- Traverse the array using fast:
  - When nums[fast] != 0, it means we found a valid non-zero element:
    - Swap nums[slow] and nums[fast].
    - Increment slow.
- After traversal:
  - All non-zero elements are placed at the front of the array.
  - All zeroes are moved to the end.
  - The array is modified in-place.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};