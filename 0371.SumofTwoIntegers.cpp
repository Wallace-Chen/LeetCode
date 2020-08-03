class Solution {
public:
    int getSum(int a, int b) {
        //int peudo_sum = a ^ b; // note that xor operation is a 'kind' of sum but does not consider carry-over
        //int carry = a & b; // AND operation can produce the carry signal
        while(b != 0){
            int peudo_sum = a;
            a = a ^ b;
            b = (unsigned int)(peudo_sum & b) << 1;
        }
        return a;
    }
};
