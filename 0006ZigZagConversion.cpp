class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if(len <= numRows || numRows==1) return s;
        string rlt="";
        for(int r=0;r<numRows; r++){
            int pos = r;
            bool toBottom = true;
            if(r==numRows-1) toBottom = false;
            while(pos < len){
                rlt += s[pos];
                if(toBottom) {
                    pos += (numRows-r-1)*2;
                    if(r>0) toBottom=false;
                }
                else {
                    pos += 2*r; 
                    if(r<numRows-1) toBottom=true;
                }
            }
        }
        return rlt;
    }
};