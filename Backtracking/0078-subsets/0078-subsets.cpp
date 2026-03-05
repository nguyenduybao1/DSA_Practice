/*
Leetcode 78 - Subsets
Pattern: Backtracking

Idea:
- At each step, record current path as a valid subset (including empty).
- Try adding each number from index `start` onwards to avoid duplicates.
- After recursing, pop the last element to backtrack and try next choice.

Example: nums = [1,2,3]
  dfs(0): path=[] → save []
    add 1 → dfs(1): path=[1] → save [1]
      add 2 → dfs(2): path=[1,2] → save [1,2]
        add 3 → dfs(3): path=[1,2,3] → save [1,2,3], pop → path=[1,2]
      pop → path=[1]
      add 3 → dfs(3): path=[1,3] → save [1,3], pop → path=[1]
    pop → path=[]
    add 2 → dfs(2): path=[2] → save [2]
      add 3 → dfs(3): path=[2,3] → save [2,3], pop → path=[2]
    pop → path=[]
    add 3 → dfs(3): path=[3] → save [3], pop → path=[]
  Result: [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]

Time Complexity: O(n * n^2)
Space Complexity: O(n)
*/
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, vector<int>& nums){
        ans.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i+1, nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};