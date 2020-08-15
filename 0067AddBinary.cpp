class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>b.size()) swap(a, b); // make sure that length of a is no longer than b
        int carryover = 0, len1 = a.size(), len2=b.size();
        for(int i=1;i<=len1 || (carryover && i<=len2) ;i++){
            carryover = ((i>len1) ? 0 : a[len1-i] - '0') + b[len2-i] - '0' + carryover;
            b[len2-i] = carryover%2 + '0';
            carryover /= 2;
        }
        if(carryover) b.insert(0, 1, '1');
        return b;
    }
};