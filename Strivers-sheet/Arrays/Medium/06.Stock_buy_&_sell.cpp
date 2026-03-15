/*
QUESTION:-
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

/*
APPROACH:
1. We initialise a variable to track the minimum price through the array.
2. We initialise two variable to track the profit, and the maxprofit out of all.
3. Traversing through the array, we find profit by subtracting current element by the minprice tracked till now in the array.
4. We take the min of the minprice and the current element to check if it is lesser than the minprice tracked till now.
5. We find the maxprofit by taking max of maxprofit and the current profit.
6. Return maxprofit.
*/

//CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int profit = 0;
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++) {
            profit = prices[i] - minprice;
            minprice = min(minprice, prices[i]);
            maxprofit = max(maxprofit, profit);
        }
        return maxprofit;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
