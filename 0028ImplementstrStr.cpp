class Solution {
public:
    int strStr(string haystack, string needle) {
        int nstring = haystack.size(), npattern = needle.size();
        int out = 0, in = 0;
        if(npattern == 0) return 0;
        vector<int> kmp(npattern, 0);
        int t = 0;
        for(int i=1;i<npattern;i++){
            if(needle[i] != needle[t]){
                while(t>0 && needle[t]!=needle[i]) t = kmp[t-1];
            }
            if(needle[i] == needle[t]) {
                t += 1;
                kmp[i] = t;
            }
        }
        
        while(out < nstring){
            if(haystack[out] == needle[in]) {
                out++; in++;
                if(in==npattern) return (out - in);
            }
            else{
                if(in == 0) out++;
                else in = kmp[in-1];
            }
        }
        return -1;
    }
};