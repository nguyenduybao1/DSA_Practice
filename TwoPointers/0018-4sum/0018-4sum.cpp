/*
Leetcode 18 - 4Sum
Pattern: TwoPointers

Idea:
- Sort the array.
- Fix the first two numbers (i, j).
- Use two pointers (left, right) to find remaining two numbers.
- Skip duplicates at every level to avoid repeated quadruplets.
- Compare sum with target to move pointers.

Time Complexity: O(n^3)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};