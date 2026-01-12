/*
Leetcode 70 - Climbing Stairs
Pattern: Dynamic Programming (Fibonacci)

Idea:
- Let f(n) be the number of ways to reach step n.
- To reach step n, the last move can be:
  + 1 step from n-1
  + 2 steps from n-2
- Therefore, the recurrence relation is:
  f(n) = f(n-1) + f(n-2)
- Base cases: 
  + f(0) = 1     Doing nothing is one valid way
  + f(1) = 1     Only one way: take one step
- Use two variables to compute the result

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1; 
        int b = 1; 
        for(int i = 2; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;

    }
};