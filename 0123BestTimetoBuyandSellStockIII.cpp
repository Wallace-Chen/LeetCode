class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) { // basic idea is to try to find the optimal split point between the two transactions, thus first scan from left is to record max profit taken from day 0 to i with only one transaction, and then scan from right to record the max profit taken from day i to the end with only one transaction.
        int s = prices.size(), min=INT_MAX, profit=0;
        vector<int> left(s, 0), right(s, 0);
        for(int i=0;i<s;i++){
            if(prices[i] < min) min=prices[i];
            left[i] = (i==0) ? 0 : max(left[i-1], prices[i]-min); // scan from the left
        }
        min=INT_MAX;
        for(int i=s-1;i>=0;i--){
            if(-prices[i] < min) min = -prices[i];
            right[i] = (i==s-1) ? 0 : max(right[i+1], -prices[i]-min); // scan from the right
            
            profit = max(profit, left[i]+right[i]); // total profit  = left scan + right scan
        }
        return profit;
    }
    */
    
    int maxProfit(vector<int>& prices) { // a clever solution
        int bal1 = INT_MIN, bal2 = INT_MIN, profit1 = 0, profit2 = 0;
        for(int i : prices){
            bal1 = max(bal1, -i); // our account balance for buying the first stock
            profit1 = max(profit1, bal1 + i); // the current balance if we sell first stock here
            bal2 = max(bal2, -i + profit1); // the net balance after buying the second stocks, note we can use the profit from stock 1 to pay the second stock
            profit2 = max(profit2, bal2 + i); // our outstanding account balance after selling the second stock here
        }
        return profit2;
    }
};
