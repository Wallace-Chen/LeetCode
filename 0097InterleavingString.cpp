/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if(s3.size() != len1+len2) return false;
        vector<vector<int> > dp = vector(len1+1, vector<int>(len2+1, 0));
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = (s3[i+j-1]==s2[j-1]) && dp[i][j-1];
                else if(j==0) dp[i][j] = (s3[i+j-1]==s1[i-1]) && dp[i-1][j];
                else{
                    dp[i][j] = ( s3[i+j-1]==s2[j-1] && dp[i][j-1] ) || ( s3[i+j-1]==s1[i-1] && dp[i-1][j] );
                }
            }
        }
        return dp[len1][len2];
    }  
};
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if(s3.size() != len1+len2) return false;
        vector<int> dp = vector<int>(len2+1, 0);
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0 && j==0) dp[j] = 1;
                else if(i==0) dp[j] = (s3[i+j-1]==s2[j-1]) && dp[j-1];
                else if(j==0) dp[j] = (s3[i+j-1]==s1[i-1]) && dp[j];
                else{
                    dp[j] = ( s3[i+j-1]==s2[j-1] && dp[j-1] ) || ( s3[i+j-1]==s1[i-1] && dp[j] );
                }
            }
        }
        return dp[len2];
    }  
};
