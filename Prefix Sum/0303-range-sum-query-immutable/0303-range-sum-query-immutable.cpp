/*
Leetcode 303 - Range Sum Query - Immutable
Pattern: Prefix Sum

Idea:
- Precompute prefix sum array where prefix[i] = sum of nums[0..i-1].
- sumRange(left, right) = prefix[right + 1] - prefix[left].
- prefix has size n+1 to avoid out-of-bounds when left = 0.

Time Complexity: O(n) build, O(1) query
Space Complexity: O(n)
*/
class NumArray {
public:
    vector<int> prefix; 
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */