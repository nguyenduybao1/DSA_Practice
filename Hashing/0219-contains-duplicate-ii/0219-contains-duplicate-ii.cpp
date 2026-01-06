/*
LeetCode 219 - Contains Duplicate II
Pattern: Hashing

Idea:
- Use a hash map to store the last index of each number
- Traverse the array from left to right
- For each element:
  - If it appeared before, check if the index difference <= k
  - If yes, return true
  - Update the index to the current position
- If no valid pair is found, return false


Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])){
                if( i - mp[nums[i]] <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};