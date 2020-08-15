class Solution {
public:
    bool isNumber(string s) {
        int len=s.size(), pos=0;
        while(pos<len && s[pos]==' ') pos++;
        if(pos==len) return false; // check the beginning of string, false if the string does not contain these symbols
        int nsign=0, ndot=0, nexp=0;
        bool numSeen = false, expSeen=false;
        while(pos<len && (s[pos]=='+' || s[pos]=='-')) {nsign++;pos++;}
        if(nsign>1) return false; // check the number of sign symbol
        while(pos < len){
            if(s[pos]=='+' || s[pos]=='-') {if(s[pos-1]=='e') ; else return false;} // false if found sign symbol later again except immediately after a 'e'
            else if(s[pos]=='e') {if(!numSeen || expSeen) return false; else {nexp++;expSeen=true;}} // false if found multiple 'e' or before a number
            else if(s[pos]=='.') {if(ndot>0 || expSeen) return false; else ndot++;} // false if found multiple '.' or after 'e'
            else if(isdigit(s[pos])) {if(!numSeen) numSeen=true; nexp = max(0, nexp-1);} 
            else if(s[pos]==' '){ // false if ' ' stops before the end of string
                while(s[pos]==' ') pos++;
                if(pos<len) return false;
            }
            else return false;
            pos++;
        }
        if(nexp>0 || !numSeen) return false; // false if no numbers after 'e' or no numbers seen
        else return true;
    }
};