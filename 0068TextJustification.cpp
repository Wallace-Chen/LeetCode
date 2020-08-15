class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> separator, ncount;
        separator.push_back(0);
        int nchars = 0, len = words.size();
        for(int i=0;i<len;i++){
            nchars += words[i].size();
            nchars += (nchars>0); // add 1 char for ' ' for each word
            if(nchars > maxWidth || i==len-1){ // we need to start a new line here
                if(nchars == maxWidth+1){
                    i ++;
                    separator.push_back(i); // old line stop at i-1
                    ncount.push_back(nchars-1);
                    nchars = 0;
                }
                else if(nchars > maxWidth){
                    separator.push_back(i); // old line stop at i-1
                    ncount.push_back(nchars-words[i].size() - 2);
                    nchars = 0; 
                }
                if(i==len-1) {
                    separator.push_back(i+1);
                    ncount.push_back(words[i].size());
                }else i--;
            }
        }
        int pos = 0, nextra = maxWidth - ncount[pos];
        vector<string> rlt(separator.size()-1);
        for(int i=0;i<len;i++){
            if(i==separator[pos+1]){ // means we have to start new line
                rlt[pos] = rlt[pos].substr(0, maxWidth); // remove the spaces we appended at the last word
                pos ++;
                nextra = maxWidth - ncount[pos];
            }
            int nw = separator[pos+1] - i, space = (nw==1) ? nextra : nextra/(nw-1) + (nextra%(nw-1)>0); //nw: the number of remainning words
            if(pos == separator.size()-2) space = 0; // if at the last line, left justified.
            if(i==len-1) space = -1;
            rlt[pos] += words[i] + string(space+1, ' ');
            if( i==len-1 ) rlt[pos] += string(maxWidth - rlt[pos].size(), ' ');
            nextra -= space;
        }
        return rlt;
    }
};