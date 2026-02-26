/*
Leetcode 3174 - Clear Digits
Pattern: Stack

Idea:
- Traverse string from left -> right.
- If character is a letter -> push into stack.
- If character is a digit -> remove closest previous letter:
    pop from stack (if exists).
- Build result by reversing stack content.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char c : s){
            if(isalpha(c)){
                st.push(c);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};