class Solution {
public:
    string minWindow(string s, string t) { // two pointers
        int len1 = s.size(), len2 = t.size();
        vector<int> cnt(128, 0);
        for(int i=0;i<len2;i++) cnt[t[i]] ++; 
        int lp = 0, rp = 0, l_min = -1, width_min = INT_MAX, num_let = 0;
        for(;rp<len1;rp++){
            if(--cnt[s[rp]] >= 0) num_let ++;
            while(num_let == len2){
                if(rp - lp + 1 < width_min){
                    width_min = rp - lp + 1;
                    l_min = lp;
                }
                
                if(++cnt[s[lp]] > 0) num_let --;
                lp ++;
           }
        }
        
        return (l_min==-1) ? "" : s.substr(l_min, width_min);
    }
};
