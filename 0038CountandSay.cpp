class Solution {
public:
    string countAndSay(int n) {
        string pre = "1", curr=pre;
        for(int i=1;i<n;i++){
            curr="";
            int fre=0, j=0;
            char target = pre[0];
            while(j<pre.size()){
                while(j<pre.size() && pre[j]==target) {j++; fre++;}
                curr += to_string(fre); curr += target;
                fre = 0; target = pre[j];
            }
            pre = curr; 
        }
        return curr;
    }
};