class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { // DP method
        int len = s.size(), maxw=0;
        vector<int> dp(len+1, 0);
        unordered_set<string> dict;
        for(auto i:wordDict){
            maxw = max(maxw, (int)i.size()); // prune branches improve a lot!!!
            dict.insert(i);
        }
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<=i;j++){
                if(i-j+1<=maxw && dp[j] && dict.find(s.substr(j,i-j+1))!=dict.end()){
                    dp[i+1] = 1;
                    break;
                }
            }
        }
        return dp.back();
    }
};
