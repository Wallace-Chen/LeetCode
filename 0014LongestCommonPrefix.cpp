class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rlt = "";
        int i=0, len = strs.size();
        if(len<=0) return rlt;
        while(1){
            char c;
            if(i < strs[0].size()) c = strs[0][i];
            else break;
            int j = 0;
            for(;j < len;){
                if( i >= strs[j].size() || strs[j][i] != c) break;
                j++;
            }
            if(j<len) break;
            else rlt += c;
            i++;
        }
        return rlt;
    }
};