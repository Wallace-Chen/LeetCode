class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        vector<int> rlt(len1+len2, 0);
        string sol;
        for(int i=0;i<len1;i++){
            int mul1 = num1[len1-i-1] - '0';
            for(int j=0;j<len2;j++){
                int mul2 = num2[len2-j-1] - '0';
                int prod = mul1 * mul2 + rlt[i+j];
                rlt[i+j] = prod%10;
                rlt[i+j+1] += prod/10;
            }
        }
        
        int i=len1+len2-1;
        while(i>=0 && rlt[i] == 0) i--;
        for(;i>=0;i--){
            sol += char(rlt[i]+'0');
        }
        
        return sol.size()==0 ? "0" : sol;
    }
};