/*
Leetcode - 169 - Majority Element
Pattern: Math - Boyer–Moore

Idea:
- Since the majority element appears more than n/2 times, 
   it cannot be completely canceled out by other numbers.
- Keep a candidate and a count.
   - If Same number → count increases.
   - If Different number → count decreases.
- When count becomes zero, choose a new candidate.
- The final candidate is the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
