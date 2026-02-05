/*
Leetcode 16 - 3Sum Closest
Pattern: Sorting + Two Pointers

Idea:
- Sort the array.
- Fix one number.
- Use two pointers to search for the closest sum to target.
- Update answer whenever we find smaller difference.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2]; 

        for(int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(sum - target) < abs(closest - target)){
                    closest = sum;
                }
                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    return target;
                }
            }
        }
        return closest;
    }
};