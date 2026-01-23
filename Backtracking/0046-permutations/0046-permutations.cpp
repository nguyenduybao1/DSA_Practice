/*
Leetcode 46 - Permutations
Pattern: Backtracking

Idea:
- Use backtracking.
- At each step:
  - Try every unused number
  - Add it to current path
  - Recurse
  - Remove it (backtrack)
- Stop when path size == n

Time Complexity: O(n! * n)
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

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};