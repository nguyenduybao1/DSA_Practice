/*
Leetcode 3507 - Minimum Pair Removal To Sort Array I
Pattern: Simulator - Greedy

Idea:
- While the array is not sorted:
    - Find the adjacent pair with the minimum sum (greedy choice).
    - Merge them into one element (replace by sum).
    - Remove the second element.
- Count how many merge operations are performed.
**We simulate the process exactly as described in the problem**

Time Complexity: O(n²)
Space Complexity: O(1)
*/
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            int minSum = INT_MAX;
            int idx = -1;
            for(int i = 0; i < nums.size() - 1 ; i++){
                if(nums[i] + nums[i+1] < minSum){
                    minSum = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() +idx +1);
            count++;
        }
        return count;
    }
};