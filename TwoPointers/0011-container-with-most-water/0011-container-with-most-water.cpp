/*
Leetcode 11 - Container with most water
Pattern: TwoPointer(Greedy - Shrinking Window)

Idea:
- Use two pointers at both ends.
- Compute area = width × min(height).
- Move the pointer with smaller height inward,
   because moving the taller one cannot increase area.
- Track maximum area.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;

            ans = max(ans, h * w);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};