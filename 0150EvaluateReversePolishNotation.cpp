class Solution {
public:
    int evalRPN(vector<string>& tokens) { //using function keyword and lamda function
        unordered_map<string, function<int(int,int)> > maps = {
            {"+", [](int a, int b){return a+b;} },
            {"-", [](int a, int b){return a-b;} },
            {"*", [](int a, int b){return a*b;} },
            {"/", [](int a, int b){return a/b;} }
        };
        stack<int> stk;
        for(auto s:tokens){
            if(maps.find(s)!=maps.end()){
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                
                stk.push(maps[s](num1,num2));
            }else{
                stk.push(stoi(s));
            }
        }
        return stk.empty() ? 0 : stk.top();
    }
    /*
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s:tokens){
            if(isOperator(s)){
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                if(s=="+") num1 = num1 + num2;
                else if(s=="-") num1 = num1 - num2;
                else if(s=="*") num1 = num1 * num2;
                else if(s=="/") num1 = num1 / num2;
                stk.push(num1);
            }else{
                stk.push(stoi(s));
            }
        }
        return stk.empty() ? 0 : stk.top();
    }
    bool isOperator(string &s){
        if(s=="+" || s=="-" || s=="*" || s=="/") return true;
        else return false;
    }
    */
};
