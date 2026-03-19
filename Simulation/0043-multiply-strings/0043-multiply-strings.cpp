/*
Leetcode 43 - Multiply Strings
Pattern: Math / String Simulation

Idea:
- Simulate grade-school multiplication using an array pos[n + m].
- For each pair of digits num1[i] and num2[j], multiply and add to position (i + j + 1),
  where (i + j + 1) stores the current digit and (i + j) stores the carry.
- Traverse from right to left, accumulate values, and handle carry using sum % 10 and sum / 10.
- Finally, build the result string by skipping leading zeros.

Time:  O(n * m)
Space: O(n + m)
*/
class Solution {
public:
    string multiply(string num1, string num2) {
       int n = num1.size();
       int m = num2.size();
       vector<int> pos(n + m, 0);

       for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + pos[i + j +1];
                int p1 = i + j + 1, p2 = i + j;

                pos[p1] = sum % 10;
                pos[p2] += sum / 10;
            }
       }

       string res;
       for(int num : pos){
            if(!(res.empty() && num == 0)){
                res += to_string(num);
            }
       }
       return res.empty() ? "0" : res;
    }
};