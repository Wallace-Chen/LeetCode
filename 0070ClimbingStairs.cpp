class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int n_2=1, n_1=2;
        for(int i=3;i<=n;i++){
            if(i==n) break;
            else n_2 = exchange(n_1, n_1+n_2);
        }
        return n_2+n_1;
    }
};