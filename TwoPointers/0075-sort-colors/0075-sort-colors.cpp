/*
Leetcode 75 - Sort Colors
Pattern: Dutch National Flag (Three Pointers)

Idea:
- Split the array into three parts: 0s on the left, 1s in the middle, and 2s on the right.
- Use three pointers to scan and partition the array.
  - If we see 0, move it to the left.
  - If we see 2, move it to the right.
  - If we see 1, just move forward.
- When swapping with the right pointer (2), do not move mid,
   because the swapped value still needs to be checked.
- All elements are sorted in one pass.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
