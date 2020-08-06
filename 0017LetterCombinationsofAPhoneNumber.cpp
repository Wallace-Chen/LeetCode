class Solution {
public:
    map<int, string> mapper = { 
        {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };
    vector<string> output = {};
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return output;
//        vector<string> rlt = {};
//        for(int i = 0;i < digits.size(); i++){
//            letterCombinations(rlt, digits.substr(i, 1));
//        }
        letterCombinations("", digits);
        return output;
    }
    
    void letterCombinations(string str, string digits){ // deep first
        if(digits.size() == 0){
            output.push_back(str);
        }else{
            int d = digits[0] - '2' + 2;
            for(char ch : mapper[d]){
                 letterCombinations(str+ch, digits.substr(1));
            }
            
        }
    }
    
    /*
    void letterCombinations(vector<string>& str, string c){ //breadth first
        int d = c[0] - '2' + 2, len = str.size();
        for(char letter : mapper[d]){
            if(len > 0 ) 
                for(int i = 0; i < len; i ++) str.push_back(str[i]+letter);
            else str.push_back(string(1,letter));
        }
        str.erase(str.begin(), str.begin()+len);
    }
    */
};