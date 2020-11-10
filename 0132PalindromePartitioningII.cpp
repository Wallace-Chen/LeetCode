class Solution {
public:
    /*
    int minCut(string s) { // convert it to a graph first, and then do BFS
        int len = s.size(), ret = 0;
        if(len==0 || len==1) {return ret;}
        vector<set<int> > dp(len, set<int>()); // dp[i] is a set, an element j in this set means: (i,j) is a pal.
        for(int i=len-1;i>=0;i--){
            dp[i].insert(i); // one char is a palindrome itself
            for(int j=i+1;j<len;j++){
                if(s[j]==s[i]){
                    if(j==i+1 || dp[i+1].count(j-1)!=0) dp[i].insert(j);
                }
            }
        }
        
        // BFS on the dp, think of it as a graph
        set<int> frontier;
        frontier.insert(0);
        while(1){
            set<int> next;
            for(int num : frontier){
                for(int i : dp[num]){
                    if(i == len-1) return ret;
                    next.insert(i+1);
                }
            }
            frontier = next;
            ret ++;
        }
        return ret; // will not execute here
    }
    */
    /*
    int minCut(string s) { // use two dimentional array isPal[i][j] to indicate whether (i,j) is a pal. And use one dimention array dp[i] to indicate the min cut needed for the string s[i:].
        int len = s.size();
        vector<vector<int> > isPal(len, vector<int>(len, 0));
        vector<int> dp(len);
        
        for(int i=len-1;i>=0;i--){
            dp[i] = len - 1 - i; // a baseline cut
            for(int j=i;j<len;j++){
                if(s[j]==s[i]){
                    if(j-i<2 || isPal[i+1][j-1]){
                        isPal[i][j] = 1;
                        if(j==len-1) dp[i] = 0;
                        else dp[i] = min( dp[i], dp[j+1]+1);
                    }
                }
            }
        }
        return dp[0];
        
    }
    */
    // Manchester method to check a string is a pal or not, and no need to use two array anymore. dp here means the min cut needed for the string s[:i]
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len);
        for(int i=0;i<len;i++) dp[i] = i;
        for(int i=0;i<len;i++){
            for(int j=0; i-j>=0 && i+j<len && s[i-j]==s[i+j];j++){ // (i-j, i+j) is a pal, odd length
                if(i-j==0) dp[i+j] = 0;
                else dp[i+j] = min(dp[i+j], dp[i-j-1] + 1);
            }
            for(int j=0; i-j>=0 && i+j+1<len && s[i-j]==s[i+j+1];j++){ // (i-j, i+j+1) is a pal, even length
                if(i-j==0) dp[i+j+1] = 0;
                else dp[i+j+1] = min(dp[i+j+1], dp[i-j-1] + 1);
            }
            
        }
        return dp[len-1];
    }
    
    
};
