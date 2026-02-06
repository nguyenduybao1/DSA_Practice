/*
Leetcode 32 - Longest Valid Parentheses
Pattern: Stack

Idea:
- Use a stack to store indices, not characters.
- Push index of '('.
- When seeing ')', pop the stack to match.
- If stack becomes empty, push current index as a new base (invalid boundary).
- Otherwise, the current valid length = i - stack.top().
- Keep updating the maximum length.

Note: Why push -1 first?
- Acts as a base index to calculate length for the first valid substring.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};