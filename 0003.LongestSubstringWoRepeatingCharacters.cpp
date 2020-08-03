class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        int rlt = 0, pos = 0;
        if(s.size() == 0) return rlt;
        string subs;
        while(!fillSubstring(pos, s, &subs)){
            if(subs.size() > rlt) rlt = subs.size();
            subs.erase(0, 1);
        }
        if(subs.size() > rlt) rlt = subs.size();
        return rlt;
    }
    
    bool fillSubstring(int &pos, string s, string *subs){
        string::iterator it = s.begin() + pos;
        while(it != s.end()){
            if(subs->find(*it)==string::npos){
                subs->append(it, it+1);
                it ++; pos ++ ;
            }
            else{
                return false;
            }            
        }        
        return true;
    }
    */
    // a better solution: optimized on the sliding window idea
    // lastrepeatPos points to the "largest" index with collision char: left of the windows, i: right of window
    // a map storing mapping between chars with their 'most recent' index
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int rlt = 0, lastrepeatPos = -1;
        for(int i=0;i<s.size(); i++){
            if(m.find(s[i]) != m.end() && m[s[i]] > lastrepeatPos){
                lastrepeatPos = m[s[i]];
            }
            if(i-lastrepeatPos > rlt) rlt = i-lastrepeatPos;
            m[s[i]] = i;
        }
        
        return rlt;
    }
};