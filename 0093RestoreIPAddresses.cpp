class Solution {
public:
    vector<string> rlt;
    int len;
    vector<string> restoreIpAddresses(string s) {
        len = s.size();
        string ip;
        restoreIpAddresses(s, ip, 0, 0);
        return rlt;
    }
    
    void restoreIpAddresses(string& s, string& ip, int pos, int cnt) {
        if(cnt == 4){
            if(pos == len) rlt.push_back(ip);
            else return;
        }
        if(pos >= len || (cnt == 3 && len-pos>3)) return;
        int numopt = 1; // the number of digits we can take
        if(s[pos]=='0') numopt = 1; // '0' can only be alone
        else{
            if(pos+1<len) numopt = 2;
            if(pos+2<len && s.substr(pos,3).compare("255")<=0) numopt = 3;
        }
        while(numopt--){
            if(len-pos-numopt-1 < 3-cnt) continue; // fast prune
            string tmp(ip);
            if(cnt == 3) tmp += s.substr(pos, numopt+1);
            else
                tmp += s.substr(pos, numopt+1) + ".";
            restoreIpAddresses(s, tmp, pos+numopt+1, cnt+1);
        }
    }
};
