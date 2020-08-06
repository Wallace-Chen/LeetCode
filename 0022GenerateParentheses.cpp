class Solution {
public:
    vector<string> rlt={};
    vector<string> generateParenthesis(int n) {
        if(n == 0) return rlt;
        generateParenthesis("", 0, 0, n);
        //generateParenthesis("(", 1, n-1, n);
        return rlt;
    }
    void generateParenthesis(string s, int left, int right, int n) {
        if(s.size() == 2*n) {rlt.push_back(s); return;}
        if(left < n) generateParenthesis(s+"(", left+1, right, n);
        if(right < left) generateParenthesis(s+")", left, right+1, n);
    }
    /*
    void generateParenthesis(string s, int i, int remain, int n) {
        if(remain == 0){
            while(i < 2*n) {s += ')'; i++;}
            rlt.push_back(s);
        }else{
            int placed = n - remain, moves = placed - (i-placed);
            string tmp = s;
            for(int move=0;move<=moves;move++){
                s = tmp;
                int nclose = 0;
                while(nclose<move) {s+=')'; nclose++;}
                s += '(';
                generateParenthesis(s, i+move+1, remain-1, n);
            }
        }
    }
    */
};