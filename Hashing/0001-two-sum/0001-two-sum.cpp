/*
LeetCode 1 - Two Sum
Pattern: Hashing (One-pass lookup)

Idea:
- Use a hash map to store numbers we have seen so far with their indices
- For each number, calculate its complement: target - current
- If the complement exists in the map, return the stored index and current index

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            int x = target - cur;

            if (mp.count(x))
            {
                return {mp[x], i};
            }

            mp[cur] = i;
        }

        return {};
    }
};
