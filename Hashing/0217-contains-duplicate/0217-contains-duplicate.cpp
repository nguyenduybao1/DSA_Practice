/*
LeetCode 217 - Contains Duplicate
Pattern: Hashing

Idea:
- Use a hash set to track numbers that have appeared
- Traverse the array:
  - If the current number already exists in the set → duplicate found
  - Otherwise, insert it into the set
- If traversal finishes without duplicates → return false

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> mp;

        for (int x : nums)
        {
            if (mp.count(x))
            {
                return true;
            }
            mp.insert(x);
        }

        return false;
    }
};