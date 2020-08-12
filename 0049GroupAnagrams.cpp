class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rlt;
        unordered_map<string, int> mapper;
        for(int i=0;i<strs.size();i++){
            string tmp(26,'0'), curr=strs[i];
            for(int j=0;j<curr.size();j++){
                tmp[curr[j]-'a'] += 1;
            }
            if(mapper.find(tmp)==mapper.end()) {
                mapper[tmp] = mapper.size();
                rlt.push_back({curr});
            }else rlt[mapper[tmp]].push_back(curr);
        }
        
        return rlt;
    }
};