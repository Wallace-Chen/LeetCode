class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        vector<int> buys(s), sells(s);
        for(int i=0;i<s;i++){
            buys[i] = (i==0) ? prices[i] : min(buys[i-1], prices[i]);
            sells[s-1-i] = (i==0) ? prices[s-1-i] : max(sells[s-i], prices[s-1-i]);
        }
        int maxp=INT_MIN;
        for(int i=0;i<s;i++) maxp = max(maxp, sells[i]-buys[i]);
        return max(0,maxp);
    }
    */
    
    int maxProfit(vector<int>& prices) { // mimic the buy and sell stock
        int min=INT_MAX, profit=0; // min:hold the minimum of price; profit: record the highest profit
        for(auto num : prices){
            if(num<min) min = num;
            else if(num-min > profit) profit = num-min;
        }
        return profit;
    }
};
