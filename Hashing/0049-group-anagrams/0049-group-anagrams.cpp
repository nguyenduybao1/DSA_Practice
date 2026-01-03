/*
Leetcode 49 - Group Anagrams
Pattern: Hashing

Approach 1: Sort
Idea:
- For each string, sort its characters to get a normalized form
- Use the sorted string as a key to group original strings together
- Strings with the same sorted key belong to the same anagram group
- Collect all groups and return them

Time Complexity: O(n * k log k)
Space Complexity: O(n * k)

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            string key = s;

            sort(key.begin(), key.end());
            
            mp[key].push_back(s);
        }
        vector<vector<string>> res;

        for(auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(it -> second);
        }
       return res;
    }
};


/*
Leetcode 49 - Group Anagrams
Pattern: Hashing

Approach 2: Character count - Better version
Idea:
- For each string, count the frequency of each character
- Use the frequency counts to build a unique key
- Strings that generate the same key are anagrams
- Group strings by this key and return all groups

Time Complexity: O(n * k)
Space Complexity: O(n * k)

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            int cnt[26] = {0};

            // Đếm tần suất ký tự
            for (char c : s) {
                cnt[c - 'a']++;
            }

            // Tạo key từ frequency
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(cnt[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& p : mp) {
            res.push_back(p.second);
        }

        return res;
    }
};

