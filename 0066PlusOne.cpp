class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size(), carryover = 1, pos=len-1;
        while(pos>=0 && carryover){
            int tmp = carryover + digits[pos];
            carryover = tmp/10;
            digits[pos] = tmp%10;
            pos--;
        }
        if(carryover!=0) digits.insert(digits.begin(), carryover);
        return digits;
    }
};

/* alternative concise conde
vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
}
*/