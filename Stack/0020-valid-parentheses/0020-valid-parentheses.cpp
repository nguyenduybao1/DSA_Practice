/*
Leetcode 20 - Valid Parenthese
Pattern: Stack (LIFO)

Idea:
- Use a stack to keep track of opening brackets.
- When a closing bracket is encountered, 
  check whether it matches the most recent opening bracket on the stack.
- The string is valid if all brackets are matched and the stack is empty at the end.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '{' || c == '[' || c == '(' ){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }

                char top = st.top();
                st.pop();
                
                if((top != '{' && c == '}') ||
                   (top != '[' && c == ']') ||
                   (top != '(' && c == ')')){
                    return false;
                   }
            }
        }
        return st.empty();
    }
};