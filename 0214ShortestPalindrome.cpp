class Solution {
public:
    /*
    string shortestPalindrome(string s) {
        int len = s.size();
        cout << len << endl;
        if(len<=1) return s;
        
        for(int i=len/2; i>=0;i--){
            int status = expandString(s, i);
            cout << status << endl;
            if(status>0){
                if(status>=len) return s; // means string s itself is a palindrome
                else{
                    string tmp = s.substr(status);
                    reverse(tmp.begin(), tmp.end());
                    return (tmp + s);
                }
            }
        }
        return s; // should not reach here
    }
    
    int expandString(string s, int center){
        int len = s.size();
        int left_letter, right_letter, left_gap, right_gap; 
        int width_letter=-1, width_gap=-1;
        bool flag1=true, flag2=true;
        if(len%2 == 0){
            left_letter = right_letter = center - 1;
            left_gap = center - 1; right_gap = center;
        }
        else{
            left_letter = right_letter = center;
            left_gap = center - 1; right_gap = center;
        }
        if(left_letter < 0 && left_gap < 0) return 0;
        while(flag1 || flag2){
            if(left_letter >= 0 && s[left_letter] == s[right_letter]) {left_letter--; right_letter++;}
            else flag1 = false;
            if(left_gap >= 0 && s[left_gap] == s[right_gap]) {left_gap--; right_gap ++;}
            else flag2 = false;
        }
        if(left_letter < 0) width_letter = right_letter;
        if(left_gap < 0) width_gap = right_gap;
        if(width_letter == width_gap == -1) return 0;
        else if(width_letter >= width_gap) return width_letter;
        else return width_gap;
    }
    */
    /*
    string shortestPalindrome(string s)
    {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n)
            return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
    */
    string shortestPalindrome(string s) // KMP algo: compute the max length prefix == suffix
    {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> f(n_new, 0);
        for (int i = 1; i < n_new; i++) {
            int t = f[i - 1];
            while (t > 0 && s_new[i] != s_new[t])
                t = f[t - 1];
            if (s_new[i] == s_new[t])
                ++t;
            f[i] = t;
        }
    return rev.substr(0, n - f[n_new - 1]) + s;
    }
};