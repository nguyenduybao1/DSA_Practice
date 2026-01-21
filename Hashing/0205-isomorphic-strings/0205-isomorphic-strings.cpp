/*
Leetcode 205 - Isomorphic Strings
Pattern: Hashing - Bijective Mapping

Idea:
Idea:
- Two strings are isomorphic if there is a one-to-one mapping between characters.
- Each character in the first string must map to exactly one character in the second string, and vice versa.
- Use two hash maps to maintain a bidirectional mapping:
  - map characters from s to t
  - map characters from t to s
- Traverse both strings simultaneously:
  - If a mapping exists but does not match, return false.
  - Otherwise, store the mapping.
- If no conflicts occur, return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mp1; 
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];

            if (mp1.count(a) && mp1[a] != b) return false;
            if (mp2.count(b) && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }
        return true;
    }
};
