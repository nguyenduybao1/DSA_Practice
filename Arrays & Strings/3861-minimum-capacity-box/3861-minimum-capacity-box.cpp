/*
Leetcode 3861 - Minimum Capacity Box
Pattern: Array / Linear Scan

Idea:
- Traverse the array, track index of the box with minimum valid capacity.
- A box is valid if capacity[i] >= itemSize.
- Update ans if current box has smaller capacity than the current best.
- Ties are broken by smallest index naturally (left to right traversal).

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize){
                 if (ans == -1 || capacity[i] < capacity[ans]) {
                    ans = i;  
                }
            }
        }
        return ans;
    }
};