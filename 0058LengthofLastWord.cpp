class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1, end=i;
        if(i<0) return 0;
        while(i>=0 && s[i]==' ') i--;
        end = i;
        for(;i>=0;i--) if(s[i]==' ') break;
        return (end-i);
    }
};