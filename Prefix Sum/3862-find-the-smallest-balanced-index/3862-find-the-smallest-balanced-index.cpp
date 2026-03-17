/*
Leetcode 3862 - Find the Smallest Balanced Index
Pattern: Prefix Sum

Idea:
- Precompute prefixSum where prefixSum[i] = sum of elements strictly to the left of i.
- Traverse from right to left, maintaining rightProduct = product of elements strictly to the right of i.
- If prefixSum[i] == rightProduct, return i immediately.
  (Since we traverse from right to left, the first match is the smallest index.)
- Use overflow-safe multiplication check to avoid exceeding long long limits.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i - 1]; 
        }

        long long rightProduct = 1;
        
        for(int i = n - 1; i >= 0; i--){
            if(prefixSum[i] == rightProduct){
                return i;
            }

            if (rightProduct > 1e18 / nums[i]) {
                rightProduct = 1e18;
            } else {
                rightProduct *= nums[i];
            }
        }
        return -1;
    }
};