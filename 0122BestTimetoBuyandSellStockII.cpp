class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX, profit=0, curr=0; //profit: total earnings, curr: profit of current transaction
        for(auto num : prices){
            if(num-min<curr){ // stock price droped, so sold it and buy in
                min=num; // buy
                profit += curr; //take the profit
                curr = 0;
            }else if(num-min>curr) { // stock price increase, recorded as a candidate sell price
                curr = num-min;
            }
        }
        profit += curr; // take the possible profit of the last transaction
        return profit;
    }
    */
    /*
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX, profit=0; //profit: total earnings
        for(auto num : prices){
            if(num-min>=0){ // take profit when any: greedy method
                profit += num-min;
                min = num;
            }else min=num;
        }
        return profit;
    }
    */
    int maxProfit(vector<int>& prices) { // even simpler code
        int profit=0; //profit: total earnings
        for(int i =1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        return profit;
    }
    
};
