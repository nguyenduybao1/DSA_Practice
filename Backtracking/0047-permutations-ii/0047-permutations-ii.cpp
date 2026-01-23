/*
Leetcode 47 - Permutations II
Pattern: Backtracking + Sorting 

Idea:
- Sort the array so duplicates stay next to each other.
- Use backtracking to build permutations.
- Use used[] to avoid reusing the same index.
- Skip duplicates:
  - If nums[i] == nums[i-1] and previous hasn't been used,
    skip to avoid generating the same permutation.

Time Complexity: O(n! * n) Worst case
Space Complexity: O(n)
*/ 
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used;

    void backtrack(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
                
            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};