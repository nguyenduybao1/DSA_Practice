/*
Leetcode 179 - Largest number 
Pattern: Greedy Sorting

Idea:
- Convert numbers to strings
- Sort with custom comparator: a comes before b if a + b > b + a
- This ensures the concatenation is maximized
- If the first element is "0", the entire number is zero
- Concatenate all strings to get the final result

Time Complexity: O(n log n * k)
Space Complexity: O(n)
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        if (arr[0] == "0") return "0";
 
        string result;
        for (const string& s : arr) {
            result += s;
        }
        
        return result;
    }
};