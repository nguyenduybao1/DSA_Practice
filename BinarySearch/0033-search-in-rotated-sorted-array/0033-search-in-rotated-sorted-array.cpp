/*
Leetcode 33 - Search in Rotated Sorted Array
Pattern: Binary Search

Idea:
- At least one half of the array is always sorted.
- Check which half is sorted via nums[left] <= nums[mid].
- If target is within the sorted half -> search that half.
- Otherwise -> search the other half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            } 

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

