/*
Leetcode 167 - Two Sum II - Input Array Is Sorted
Pattern: TwoPointers

Idea:
- Use two pointers because the array is sorted
- Left starts from the beginning, right starts from the end
 - If current sum is smaller than target, move left to increase the sum
 - If current sum is greater than target, move right to decrease the sum
 - If sum equals target, return the 1-based indices

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; 
        int right = numbers.size() - 1;
        while( left < right ){
            int sum = numbers[left] + numbers[right];
            if( sum == target ){
                return {left + 1, right + 1};
            }else if( sum < target ){
                left++;
            }else if( sum > target ){
                right--;
            }
        }
        return {};
    }
};