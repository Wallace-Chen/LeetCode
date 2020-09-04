class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rlt;
        for(int i=0;i<(1<<n);i++) rlt.push_back(i^(i>>1)); //convert binary number to Gray number
        return rlt;
    }
};
