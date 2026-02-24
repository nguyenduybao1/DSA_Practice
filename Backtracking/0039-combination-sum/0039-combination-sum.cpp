/*
Leetcode 39 - Combination Sum
Pattern: Backtracking / DFS (Combination)

Idea:
- Sort candidates to enable pruning.
- Use DFS to try each candidate starting from index.
- At each step:
    - choose candidate
    - reduce remaining sum
    - recurse with same index (reuse allowed)
    - backtrack
- If remaining becomes 0 -> valid combination.
- If candidate > remaining -> stop branch.

Time Complexity: O(2^target) 
Space Complexity: O(target)
*/
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> cand;
        void dfs(int start, int remain){
            if(remain == 0){
                ans.push_back(path);
                return;
            }
            for(int i = start; i < cand.size(); i++){
                if(cand[i] > remain){
                    break;
                }
                path.push_back(cand[i]);
                dfs(i, remain - cand[i]);
                path.pop_back();
            }
        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = candidates;
        sort(cand.begin(), cand.end());

        dfs(0, target);
        return ans;
    }
};