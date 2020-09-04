class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if(len==0) return false; //return false if empty string
        vector<int> freq(26, 0);
        for(int i=0;i<len;i++) {
            freq[s1[i]-'a'] ++;
            freq[s2[i]-'a'] --;
        }
        for(int i=0;i<26;i++) if(freq[i]!=0) return false; // false if words frequency is not equal between s1 and s2
        if(len<=3) return true; // it's guaranteed that if the length is smaller or equal than 3, return true
        int pos=0;
        while(pos<len && s2[pos]!=s1[0] && s2[pos] != s1[len-1]) pos ++; // advance until we find the 'ends chars' of s1 in s2.
        while(pos<len-1){ // check recursively for each possible spliting points
            if(isScramble(s1.substr(0, pos+1), s2.substr(0, pos+1)) && isScramble(s1.substr(pos+1), s2.substr(pos+1))) return true;
            if(isScramble(s1.substr(len-pos-1),s2.substr(0, pos+1)) && isScramble(s1.substr(0,len-pos-1), s2.substr(pos+1))) return true;
            pos++;
        }
        return false;
    }
};
