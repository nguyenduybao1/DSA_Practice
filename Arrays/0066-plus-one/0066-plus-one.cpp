/*
Idea:
- Start from the last digit
- If digit < 9, increment and return
- If digit == 9, set to 0 and continue
- If all digits are 9, insert 1 at the beginning
*/

// LeetCode 66 - Plus One
// Pattern: Array / Digit Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int x = digits.size();
        for (int i = x - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);

        return digits;
    }
};