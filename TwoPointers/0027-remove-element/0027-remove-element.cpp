/*
Leetcode 27 - Remove Element
Pattern: TwoPointers

Idea:
- We need to remove all occurrences of a given value val.
- The order of elements does not matter.
- Use Two Pointers:
  - j (read pointer) to traverse the array.
  - i (write pointer) to store elements that are NOT equal to val.
- When nums[j] != val, it means this element should be kept:
  - Write nums[j] to nums[i] and increment i.
- After traversal, i is the number of remaining elements (k),
  and the first k elements of nums contain the result.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};