class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len==0 || s[0]=='0') return 0; // false if code starts with '0'
        int dp1=1, dp2=1;
        for(int i=1;i<len;i++){
            int tmp(dp2);
            if(s[i] == '0') {
                if(s[i-1]>='3' || (i<len-1 && s[i+1] == '0')) return 0; // false if code has multuple '0's, or the digit before '0' greater than 2
                else{
                    dp2 = dp1;
                    i++; // skip the digit right after the '0'
                    continue;
                }
            }
            else if((s[i-1]-'0')*10+s[i]-'0'<=26) dp2 += dp1;
            dp1 = tmp;
        }
        return dp2;
    }
};
