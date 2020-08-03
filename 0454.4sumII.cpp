class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int rlt=0;
        unordered_map<int, int> map_sum;
        for(int a: A)
            for(int b: B)
                map_sum[a+b] ++;
        
        for(int c: C)
            for(int d: D){
                auto it = map_sum.find(-c-d);
                if(it != map_sum.end()) rlt += it->second;
            }
        
        return rlt;
    }
};