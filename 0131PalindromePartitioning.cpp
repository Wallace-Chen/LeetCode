class Solution {
public:
    vector<vector<string> > out;
    int len=0;
    vector<vector<string>> partition(string s) {
        len = s.size();
        if(len==0) {out.push_back(vector<string>());return out;}
        vector<set<int> > dp(len, set<int>());
        for(int i=len-1;i>=0;i--){
            dp[i].insert(i); // one char is a palindrome
            for(int j=i+1;j<len;j++){
                if(s[j]==s[i]){
                    if(j==i+1 || dp[i+1].count(j-1)!=0) dp[i].insert(j);
                }
            }
        }
        vector<string> comb;
        constructOutputs(s, 0, dp, comb);
        return out;
    }
    
    void constructOutputs(string &s, int pos, vector<set<int> > & dp, vector<string> comb){
        if(pos>=len) return;
        for(int i : dp[pos]){
            comb.push_back(s.substr(pos, i-pos+1));
            if(i==len-1) out.push_back(comb);
            constructOutputs(s, i+1, dp, comb);
            comb.pop_back();
        }
    }
};
