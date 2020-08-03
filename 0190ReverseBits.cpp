class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
//        uint32_t rlt=0;
//        for(int i=0;i<32;i++){
//            rlt = rlt << 1 | (n & 1);
//            n = n >> 1;
//        }
        return reverse(n, 16);
    }
    uint32_t reverse(uint32_t n, int i){
        if(i==1) return( (n&1)<<1 | (n&2)>>1 );
        uint32_t right = n & int(pow(2, i) - 1);
        return (reverse(right, i/2) << i | reverse((n-right)>>i, i/2));
    }
};