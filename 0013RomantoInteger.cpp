class Solution {
public:
    map<string, int> converter = { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D",500}, {"M", 1000} };
    int romanToInt(string s) {
        int rlt=0, i = s.size()-1, last = 0;
        while(i>=0){
            int curr = converter[s.substr(i, 1)];
            if( curr >= last) rlt += curr;
            else rlt -= curr;
            last = curr; i--;
        }
        return rlt;
    }
};