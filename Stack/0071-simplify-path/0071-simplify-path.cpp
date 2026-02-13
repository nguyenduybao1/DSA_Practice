/*
Leetcode 71 - Simplify Path 
Pattern: Stack / Simulation

Idea:
- Split the path by '/'.
- Ignore empty strings and ".".
- If token is "..", pop from stack if not empty.
- Otherwise, push the directory name into stack.
- Join all elements in stack with "/" and prefix with "/".
- If stack is empty, return "/".

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string token;
        stringstream ss(path);

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }
            else if(token == ".."){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(token);
            }
        }
        
        string res = "/";
        for (int i = 0; i < st.size(); i++) {
            res += st[i];
            if (i + 1 < st.size()) res += "/";
        }

        return res;
    }
};