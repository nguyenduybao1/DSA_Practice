/*
Leetcode 42 - Trapping Rain Water
Pattern: Monotonic Stack

Approach 1: Stack
Idea:
- Use a stack to store indices of bars in decreasing height order.
- When current bar is higher than stack top, we found a right boundary.
- Pop the middle (bottom) bar to calculate trapped water.
- The new stack top becomes the left boundary.
  - width = distance between left and right - 1
  - height = min(left_height, right_height) - bottom_height
- Add width * height to answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        int n = height.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[i] >= height[st.top()]){
                int bottom = st.top();
                st.pop();
                if(st.empty()) break;

                int left = st.top();
                int width = i - left - 1;
                int water_height = min(height[left], height[i]) - height[bottom];

                ans += width * water_height;
            }
            st.push(i);
        }
        return ans;
    }
};

/*
Approach 2: TwoPointers(Better Approach)

Idea:
- Use two pointers from both ends.
- Always process the shorter side.
- If left < right:
    water depends on leftMax.
- Else:
    water depends on rightMax.
- Accumulate trapped water while moving pointers.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
   int trap(vector<int>& h) {
    int l = 0, r = h.size()-1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while(l < r) {
        if(h[l] < h[r]) {
            leftMax = max(leftMax, h[l]);
            water += leftMax - h[l];
            l++;
        } else {
            rightMax = max(rightMax, h[r]);
            water += rightMax - h[r];
            r--;
        }
    }
    return water;
    }
};