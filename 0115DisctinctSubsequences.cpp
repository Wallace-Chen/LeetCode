class Solution {
public:
    int numDistinct(string s, string t) { // dp method, use m*n space
         int s1 = s.size(), s2 = t.size();
        vector<vector <double> > dp(s1+1, vector<double>(s2+1, 0));
        for(int i=0;i<s2+1;i++){
            for(int j=i;j<s1+1;j++){
                if(i==0) dp[j][i] = 1; // any string could match an empty string
                else dp[j][i] = dp[j-1][i] + (s[j-1]==t[i-1] ? dp[j-1][i-1] : 0);
            }
        }
        return dp[s1][s2];
    }
    
    /*
    int numDistinct(string s, string t) { // only use one vector
        int s1 = s.size(), s2 = t.size();
        double pre;
        vector<double> dp(s2+1,0);
        dp[0]=1;
        for(int i=1;i<s1+1;i++){
            pre = dp[0];
            for(int j=1;j<s2+1;j++){
                pre = exchange(dp[j], dp[j] + (s[i-1]==t[j-1] ? pre : 0));
            }
        }
        return dp[s2];
    }
    */
};
