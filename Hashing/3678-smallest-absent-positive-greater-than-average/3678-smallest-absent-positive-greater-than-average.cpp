/*
Leetcode 3678 - Smallest Absent Positive Greater Than Average
Pattern: Hashing

Idea:
- Compute the average of the array.
- Store all positive numbers in a set.
- Iterate from 1 upward to find the smallest positive integer 
   that is not in the set and is strictly greater than the average.
   
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
            unordered_set<int> st;
        int maxVal = 0;
        double sum = 0;

        for(int x : nums){
            sum += x;
            if(x >0){
                st.insert(x);
                maxVal = max(maxVal, x);
            }
        }

        double avg = sum / nums.size(); 
        for(int x = 1; x <= maxVal + 1; x++){
            if(x > avg && st.count(x) == 0){
                return x;
            }
        }
        return maxVal +1;
    }
};