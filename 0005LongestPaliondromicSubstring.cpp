class Solution {
public:
    string longestPalindrome(string s) {
        string rlt;
        int len = s.size();
        if(len==1) return s;
        if(len==2) {
            if(s[0]==s[1]) return s;
            else {rlt.push_back(s[0]); return rlt;}
        }
        for(int i=0;i<=(len-1)/2;i++){
            
            string tmp = growString(s, len/2-1-i);
            if(tmp.size() > rlt.size()) rlt = tmp;      
            if(i>0) {
                string tmp = growString(s, len/2-1+i);
                if(tmp.size() > rlt.size()) rlt = tmp;
                if(len-2*i<=tmp.size()) return rlt;
            }
        }
       
        return rlt;
    }
    
    string growString(string s, int i){
        int len = s.size();
        if(i<0 || i>len-1) return string("");
        string cand1, cand2;
        if(i<len-2) cand2 = s[i+1];
        int window = min(i+1, len-i-1);
        for(int slide=0;slide<window;slide++) {
            if(s[i-slide]==s[i+1+slide] && cand1.size()==2*slide) {cand1.insert(0, s, i-slide, 1); cand1.append(s, i+1+slide, 1);}
            if(i<len-2 && s[i-slide]==s[i+2+slide] && cand2.size()==2*slide+1) {cand2.insert(0, s, i-slide, 1);cand2.append(s, i+2+slide, 1);}
            if(cand1.size()!=2*(slide+1) && cand2.size()!=2*(slide+1)+1) break;
        }
        if(cand2.size()>cand1.size()) return cand2;
        else return cand1;
    }
};