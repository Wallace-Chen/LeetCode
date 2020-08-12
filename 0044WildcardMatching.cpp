class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool> > dp(len1+1, vector(len2+1, false)); // intialize all to false
        dp[0][0] = true; // base case to true, 0 means the empty string
        
        for(int i=0;i<=len1;i++){
            for(int j=1;j<=len2;j++){ // pattern string cannot be empty, otherwise it doesn't match except the base case
                if(p[j-1] == '*'){
                    // check if * match a empty sequence
                    if(dp[i][j-1]) dp[i][j] = true;
                    else if( i>0 && dp[i-1][j] ) dp[i][j] = true; // * will then need to match some sequence
                }else if(i>0 && (s[i-1] == p[j-1] || p[j-1]=='?') && dp[i-1][j-1] ) dp[i][j] = true;
            }
        }
        return dp[len1][len2];
    }
};