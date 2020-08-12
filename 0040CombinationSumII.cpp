class Solution {
public:
    vector<vector<int> > rlt;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, sol, 0);
        return vector<vector<int> >(rlt.begin(), rlt.end());
    }
    
    void combinationSum(vector<int>& candidates, int target, vector<int>& sol, int begin) {
        if(target==0) {rlt.push_back(sol);return;}
        for(int i=begin;i<candidates.size();i++){
            if(candidates[i]<=target) {sol.push_back(candidates[i]); combinationSum(candidates, target-candidates[i], sol, i+1);sol.pop_back();}
            while(i+1<candidates.size() && candidates[i+1]==candidates[i]) i++;
        }
        return ;
    }
};