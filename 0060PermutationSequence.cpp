class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++) s += ('0' + i); // this is the first element
        int pt = 0;
        while(k>1){
            int base = factorial(n-pt-1);
            if(k>base){ // if k>base, means we have to update the value of s[pt] to (k-1)/base + 1.
                string tmp = "";
                tmp += s[pt+(k-1)/base];
                s.erase(pt+(k-1)/base, 1); // the following two lines are to move s[pt+(k-1)/base] to the position pt.
                s.insert(pt, tmp);
                k = (k-1)%base + 1;
            }
            pt ++;
        }
        return s;
    }
    
    int factorial(int n)// a function to caculate n!
    {
        if (n < 0 ) return 0;
        return !n ? 1 : n * factorial(n - 1);
    }
};