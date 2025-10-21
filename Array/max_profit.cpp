/*
    Problem: Best Time to Buy and Sell Stock
    ----------------------------------------
    You are given an array 'prices' where prices[i] represents the price of a stock 
    on the i-th day.

    You want to maximize your profit by choosing a single day to buy one stock 
    and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction.
    If you cannot achieve any profit, return 0.

    Example 1:
    ----------
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: 
        Buy on day 2 (price = 1) 
        Sell on day 5 (price = 6) 
        Profit = 6 - 1 = 5

    Example 2:
    ----------
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: 
        In this case, no transactions are done 
        and the max profit = 0.

    Constraints:
    ------------
    - 1 <= prices.length <= 10^5
    - 0 <= prices[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // To track the lowest price encountered so far
        int maxProfit = 0;       // To track the highest profit found

        for (int price : prices) {
            // Update minimum price if we find a new lower price
            minPrice = min(minPrice, price);

            // Calculate potential profit if sold at current price
            int profit = price - minPrice;

            // Update maximum profit if current profit is greater
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit; // Returns 0 if no profit is possible
    }
};

// Example driver code
int main() {
    Solution sol;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "Example 1 Output: " << sol.maxProfit(prices1) << endl;  // Expected: 5
    cout << "Example 2 Output: " << sol.maxProfit(prices2) << endl;  // Expected: 0

    return 0;
}
