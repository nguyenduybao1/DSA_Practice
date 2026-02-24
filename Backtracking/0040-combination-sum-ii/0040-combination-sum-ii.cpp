/*
Leetcode 40 - Combination Sum II
Pattern: Backtracking / DFS (Combination with duplicates)

Idea:
- Sort candidates.
- DFS with start index and remaining sum.
- Skip duplicates at same depth.
- Recurse with i+1 (no reuse).
- Stop when candidate > remain.

Time Complexity: O(2^n)
Space Complexity: O(n)
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
                if(cand[i] > remain) break;

                if (i > start && cand[i] == cand[i - 1]) continue;
                
                path.push_back(cand[i]);
                dfs(i + 1,remain - cand[i]);
                path.pop_back();
            }
        }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        cand = candidates;
        sort(cand.begin(), cand.end());

        dfs(0, target);
        return ans;
    }
};