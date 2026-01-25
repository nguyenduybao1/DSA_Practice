/*
Leetcode 122 - Best time to buy and sell stock II
Pattern: Greedy

Approach 1: Add diffs (Best solution)
Idea:
- Add every positive difference.
- If today’s price is higher than yesterday,
  take that profit immediately.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }

        return profit;
    }
};


/*
Approach 2: Segment

Idea:
- Track the start of each increasing segment as buy price.
- When price drops, sell at previous day and add profit.
- Repeat for all segments.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int totalProfit = 0;
    
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[i-1]){
                totalProfit += prices[i-1] - minPrice;
                minPrice = prices[i];
            }
        }
        totalProfit += prices.back() - minPrice;
        return totalProfit;
    }
};

/*
Approach 3: Peak - Valley 

Idea:
- Scan the array to find every valley (local minimum),
   then find the next peak (local maximum),
   add profit = peak - valley.
- Repeat until the end.


Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int i = 0;
    int buy, sell, profit = 0;
    int n = prices.size()-1;
    
    while(i < n){
        while(i < n && prices[i+1] <= prices[i]) i++;
        buy = prices[i];
        while(i < n && prices[i+1] > prices[i]) i++;
        sell = prices[i];

        profit += sell - buy;
    }
    return profit;
}

};
