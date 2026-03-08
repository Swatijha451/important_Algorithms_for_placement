#include <iostream>
#include <vector>
using namespace std;
// leetcode problem 122: Best Time to Buy and Sell Stock
//  You are given an array prices where prices[i] is the price of a given stock on the ith day.
//  On each day, you may decide to buy and/or sell the stock.
int maxProfit(vector<int> prices)
{
    int maxProfit = 0;
    int bestBuy = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy)
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result << endl;
}
