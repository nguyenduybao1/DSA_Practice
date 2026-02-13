/*
Leetcode 739 - Daily Temperatures
Pattern: Monotonic Stack (Decreasing Stack)

Idea:
- Use a monotonic decreasing stack storing indices.
- Iterate through temperatures.
- While current temperature is higher than stack top:
    pop index and calculate waiting days.
- Push current index into stack.
- Remaining indices have no warmer future day.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prev = st.top();
                answer[prev] = i - prev;
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};