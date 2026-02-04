/*
Leetcode 38 - Count and Say
Pattern: String Simulation / Two Pointers

Idea:
- Start with "1".
- For each iteration, scan the previous string and group consecutive identical digits.
- Count how many times a digit appears and append "count + digit" to build the next string.
- Repeat until reaching n.

Time Complexity: O(n * 2ⁿ)
Space Complexity: O(2ⁿ)
*/
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 2; i <= n; i++){
            string cur = "";
            int j = 0;
            while(j < res.size()){
                int count = 1;
                while(j + 1 < res.size() && res[j] == res[j+1]){
                    j++;
                    count++;
                }

                cur += to_string(count);
                cur += res[j];
                j++;
            }
            res = cur;
        }
        return res;
    }
};