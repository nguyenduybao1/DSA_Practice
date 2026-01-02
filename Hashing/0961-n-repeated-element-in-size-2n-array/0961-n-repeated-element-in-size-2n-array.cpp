/*
Leetcode 961: N-Repeated Element in Size 2N Array
Pattern: Hashing

Idea:
- Use a hash set to record elements that have already been seen
- Traverse the array and check each element:
  - If the element is already in the set, it must be the one repeated n times, so return it immediately
  - Otherwise, insert the element into the set
- Since the problem guarantees exactly one element is repeated, the answer will be found during traversal

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> hs;
        for (int n : nums)
        {
            if (hs.count(n))
            {
                return n;
            }
            hs.insert(n);
        }
        return -1;
    }
};
/*
- Because the array has a special structure, we can solve it in O(1) extra space by comparing nearby elements.

Time Complexity: O(n)
Space Complexity: O(1)
 */
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        for (int i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
            if (i + 2 < nums.size() && nums[i] == nums[i + 2])
                return nums[i];
        }
        return -1;
    }
};
