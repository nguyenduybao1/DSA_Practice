/*
Leetcode 28 - Find the Index of the First Occurrence in a String
Pattern: String Matching

Idea:
- Try matching needle starting from each valid index in haystack.
- Compare characters one by one.
- Return index if fully matched.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i <= n - m; i++){
            int j = 0;
            while(j < m && haystack[i + j] == needle[j]){
                j++;
            }
            if(j == m) return i;
        }
        return -1;
    }
};