class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];
        int n=prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] < min_buy){
                min_buy = prices[i];
            } else if(max_profit < (prices[i] - min_buy)){
                max_profit =  prices[i] - min_buy;
            }   
        }

        return max_profit;
    }
};
