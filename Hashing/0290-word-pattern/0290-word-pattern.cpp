/*
Leetcode 290 - Word Pattern
Pattern: Hashing - Bijective Mapping (Two-way Mapping)

Idea:
- Split the string s into words.
- If number of words != pattern length, return false.
- Use two hash maps to maintain a one-to-one mapping:
  char -> word and word -> char.
- If any mapping conflicts, return false.
- Return true if all pairs match.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while(ss >> word){
            words.push_back(word);
        }
        
        if(words.size() != pattern.size()){
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for(int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            string w = words[i];
            if(mp1.count(c) && mp1[c] != w){
                return false;
            }
            if(mp2.count(w) && mp2[w] != c){
                return false;
            }

            mp1[c] = w;
            mp2[w] = c;
        }
        return true;
    }
};