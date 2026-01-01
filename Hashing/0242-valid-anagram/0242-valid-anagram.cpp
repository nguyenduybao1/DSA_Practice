/*
Leetcode 242: Valid Anagram
Pattern: Hash Map (Frequency Count)

Idea:
- If two strings have different lengths, they cannot be anagrams
- Count the frequency of each character in the first string
- Decrease the count while traversing the second string
- If any count becomes negative, the strings are not anagrams

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]--;
            if (mp[t[i]] < 0)
            {
                return false;
            }
        }

        return true;
    }
};