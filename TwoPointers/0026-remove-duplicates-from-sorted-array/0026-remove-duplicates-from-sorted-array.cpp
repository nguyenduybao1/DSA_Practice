/*
Leetcode 26 - Remove Duplicates from Sorted Array
Pattern: TwoPointers

Idea:
- The array is sorted, so duplicate elements are adjacent.
- Keep the first element since it is always unique.
- Use Two Pointers:
  - j (read pointer) to traverse the array.
  - i (write pointer) to store the next unique element.
- When nums[j] != nums[i - 1], it means we found a new unique value:
  - Write nums[j] to nums[i] and increment i.
- After traversal, i is the number of unique elements (k),
  and the first k elements of nums contain the result.


Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int i = 1;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i-1]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};