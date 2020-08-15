class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector <int> > dp(len1+1, vector<int>(len2+1, INT_MAX)); // index len1 or len2 means empty string
        dp[len1][len2] = 0; // zero operation for two empty strings
        for(int i=len1-1;i>=0;i--) dp[i][len2] = len1-i; // initialize dp when word2 is empty
        for(int j=len2-1;j>=0;j--) dp[len1][j] = len2-j; // initialize dp when word1 is empty
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                if (word1[i]==word2[j]) dp[i][j]  = dp[i+1][j+1];
                else dp[i][j] = min( dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]) ) + 1; // dp[i+1][j+1] means we do a replace word1[i] with word2[j], dp[i][j+1] means a insertion of word2[j] right before word1[i], dp[i+1][j] means a deletion of word1[i].
            }
        }
        return dp[0][0];
    }
};