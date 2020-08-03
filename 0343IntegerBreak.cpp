class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        else if(n==3) return 2;
        vector<int> prod{0, 0, 1,2, 4}; // for num=0,1,2, 3 placeholder for n=0,1
        for(int i=5;i<=n;i++){
            getProd(i, prod);
        }
       return prod[n];
    }
    
    void getProd(int n, vector<int> &vec){
        int prd1=max(n-2, vec[n-2]), prd2=max(n-3, vec[n-3]);
        vec.push_back(max(2*prd1, 3*prd2));
    }

};