class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int digit = log10(x);
        while(digit>=(log10(x))/2){
            int right = (x/(int)pow(10, (int)log10(x)-digit))%10, left = (int)(x/pow(10, digit))%10;
            if(right != left) return false;
            digit --;
        }
        return true;
    }
};