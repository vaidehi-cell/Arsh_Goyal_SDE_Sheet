class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();
        vector<int> mx(n+1);
        mx[n] = 0;
        mx[n-1] = prices[n-1];
        for(int i = n-2; i > -1; i--)
            mx[i] = max(mx[i+1], prices[i]);
        for(int i = 0; i < n; i++)
            profit = max(profit, mx[i+1]-prices[i]);
        return profit;
    }
};
