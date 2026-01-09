/*
Leetcode 12 - Integer to Roman
Pattern: Greedy

Idea:
- Use greedy approach
- Prepare Roman symbols with their values in descending order
- Always subtract the largest possible value from the number
- Append the corresponding Roman symbol to the result
- Repeat until the number becomes 0

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string intToRoman(int num) {
        // Roman symbols and their values (descending order)
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };

        string result = "";

        for(int i = 0; i < roman.size(); i++){
            int value = roman[i].first;
            string symbol = roman[i].second;

            while(num >= value){
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
