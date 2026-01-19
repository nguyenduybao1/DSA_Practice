/*
Leetcode 69 - Sqrt(x)
Pattern: BinarySearch

Idea:
- Use binary search for the largest mid such that mid * mid <= x.

Time Complexity: O(log x)
Space Complexity: O(1)
*/  
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }

        int l = 1;
        int r = x/2;
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(mid <= x/mid){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};