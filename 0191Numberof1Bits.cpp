class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        while(n>0){
//            n = n & (n-1);num++; // observation: n&(n-1) will surely flip the least significant 1 bit to 0.
            if(n&1) num++;
            n = n>>1;
        }
        return num;
    }
};