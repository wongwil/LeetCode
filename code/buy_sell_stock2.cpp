class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_price = prices[0];

        for(int i=1; i < prices.size(); i++){
            if(buy_price < prices[i]){
                // there is a higher price, we sell
                max_profit += prices[i] - buy_price;
                buy_price = prices[i];
            } else if (buy_price > prices[i]){
                // there is a cheaper buy price, no profit but better "potential" for profit
                buy_price = prices[i];
            }
        }

        return max_profit;
    }
};
