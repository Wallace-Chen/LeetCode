class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size(), maxw=0;
        vector<int> dp(len+1, 0);
        unordered_set<string> dict;
        vector<vector<string> > ret(len+1, vector<string>());
        ret[0] = {""};
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
        
        if(!dp.back()) return vector<string>(); // cannot be separated, return it
        
        for(int i=0;i<len;i++){
            if(!dp[i+1]) continue;
            vector<string> &tmp = ret[i+1];
            for(int j=0;j<=i;j++){
                if(i-j+1<=maxw && dp[j] && dict.find(s.substr(j,i-j+1))!=dict.end()) {
                for(auto str:ret[j]){
                    string sentence = (str=="" ? "" : str+" ") + s.substr(j,i-j+1);
                    tmp.push_back(sentence);
                    }
                }
            }
        }
        
        return ret.back();
    }
};
