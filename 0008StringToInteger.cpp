class Solution {
public:
    int myAtoi(string str) {
        int rlt=0, index=0, len=str.size();
        bool sign = true;
        while( index<len && str[index]==' ' ) index++;
        if(index==len) return 0;
        if(str[index] == '+' || str[index] == '-') sign = (str[index]=='+') ? true : false;
        else if(isdigit(str[index])) rlt += int(str[index] - '0');
        else return 0;
        index++;
        while( index<len && isdigit(str[index]) ){
            int digit = int(str[index] - '0');
            if( sign && rlt>(INT_MAX-digit)/10 ) return INT_MAX;
            if( !sign && rlt<(INT_MIN+digit)/10 ) return INT_MIN;
            if(sign)    rlt = rlt * 10 + digit;
            else rlt = rlt * 10 - digit;
            
            index++;
        }
        
        return rlt;
    }
};