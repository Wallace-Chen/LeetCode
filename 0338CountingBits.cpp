class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0) return vector<int>{0};
        vector<int> rlt{0,1};
//        int index=1;
        for(int i=2;i<=num;i++){
//            if(2*index==rlt.size()) index=0;
//            rlt.push_back(rlt[index]+1);
//            index++;
            rlt.push_back(1 + rlt[i&(i-1)]);
        }
        return rlt;
    }
};