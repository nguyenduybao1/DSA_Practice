/*
Leetcode 8 - String to integer Atoi
Pattern: Simulation / String Parsing

Idea:
- Skip leading spaces.
- Check optional sign (+/-).
- Read digits and build number.
- Stop when non-digit appears.
- Handle overflow using long or boundary checks.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long num = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int d = s[i] - '0';

            if (num > (LLONG_MAX / 10)) break;
            num = num * 10 + d;

            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }
        return sign * num;
    }
};
