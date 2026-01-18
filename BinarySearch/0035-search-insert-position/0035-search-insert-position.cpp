/*
Leetcode 35 - Search Insert Position
Pattern: BinarySearch

Idea:
- The array is sorted, so we use binary search.
- We look for the first index where the value is greater than or equal to the target.
- If the target is not found, the left pointer will end at the correct insert position.
- Return left.

Time Complexity: O(log n)
Space Complexity: O(n)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};