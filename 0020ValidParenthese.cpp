class Solution {
public:
    map<char, char> pairs = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
           if(c=='(' || c=='[' || c=='{') st.push(pairs[c]);
            else{
                if(!st.empty() && c==st.top()) st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};