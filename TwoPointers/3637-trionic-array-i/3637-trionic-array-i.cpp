/*
Leetcode 3637 - Trionic Array I
Pattern:  Linear Scan(Monotonic Segments)

Idea:
- Scan the array in three monotonic phases:
  increasing -> decreasing -> increasing.
- Each phase must be non-empty.
- If we reach the end exactly after the third phase, return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;
        while (i < n - 1 && nums[i] < nums[i+1]) i++;
        if (i == 0) return false;

        int j = i;
        while (j < n - 1 && nums[j] > nums[j+1]) j++;
        if (j == i || j == n - 1) return false;

        int k = j;
        while (k < n - 1 && nums[k] < nums[k+1]) k++;

        return k == n - 1;
    }
};
