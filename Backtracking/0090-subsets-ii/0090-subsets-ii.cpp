/*
Leetcode 90 - Subsets II
Pattern: Backtracking

Idea:
- Same as Subsets I (LC 78), but nums may contain duplicates.
- Sort nums first so duplicates are adjacent → easy to skip.
- Key dedup rule: if i > start && nums[i] == nums[i-1] → skip.
  (only skip duplicate at the same level, not across levels)

Example: nums = [1,2,2] after sort
  dfs(0): path=[] → save []
    add 1 → dfs(1): path=[1] → save [1]
      add 2 → dfs(2): path=[1,2] → save [1,2]
        add 2 → dfs(3): path=[1,2,2] → save [1,2,2], pop
      pop
      i=2: 2==2 & i>start → skip
    pop
    add 2 → dfs(2): path=[2] → save [2]
      add 2 → dfs(3): path=[2,2] → save [2,2], pop
    pop
    i=2: 2==2 & i>start → skip
  Result: [[], [1], [1,2], [1,2,2], [2], [2,2]]

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
            if(i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(i+1,nums);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ans;
    }
};