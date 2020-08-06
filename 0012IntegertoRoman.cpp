class Solution {
public:

    map<string, int> converter = { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D",500}, {"M", 1000} };
    vector<string> letters = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        return convert(num);
    }
    string convert(int num){
        string rlt;
        int i=0;
        while(num > 0){
            while(num - toNumber(letters[i]) >= 0) {num -= toNumber(letters[i]); rlt += letters[i];}
            i ++;
        }
        return rlt;
    }
    
    int toNumber(string str){
        if(str.size() == 1) return converter[str];
        else return ( converter[str.substr(1)] - converter[str.substr(0, 1)] );
    }
};