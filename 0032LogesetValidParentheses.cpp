class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses(s, 0);
    }
    
    int longestValidParentheses(string &s, int start) {
        int len = s.size();
        if((len-start)<=1) return 0;
        vector<int> dp(len+1, 0);
        int rlt=0;
        for(int i=0; i<len; i++){
            if(s[i] == ')' && i>0){
                if(s[i-1] == '(') {dp[i] = 2 + (i-2>=0 ? dp[i-2] : 0); if(dp[i]>rlt) rlt = dp[i];}
                else if(s[i-1] == ')') {
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0);
                        if(dp[i]>rlt) rlt = dp[i];
                    }
                }
            }
        }
        return rlt;
    }
};