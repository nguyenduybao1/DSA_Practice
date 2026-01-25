/*
Leetcode 121 - Best time to buy and sell stock 
Pattern: Greedy

Idea:
- Scan from left to right.
- Keep track of the minimum price so far (best buy).
- For each day, calculate profit = price - minPrice.
- Update maximum profit.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};