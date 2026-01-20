/*
Leetcode 345 - Reverse Vowels of a String
Pattern: TwoPointers

Idea:
- Use two pointers l (left) and r (right).
  - Move l until it points to a vowel.
  - Move r until it points to a vowel.
  - Swap s[l] and s[r].
- Continue until l >= r

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while( left < right){
            if(isVowel(s[left]) && isVowel(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }else{
                if(!isVowel(s[left])){
                    left++;
                }
                if(!isVowel(s[right])){
                    right--;
                }
            }
        }
        return s;
    }
};