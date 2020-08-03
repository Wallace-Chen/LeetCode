class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> rlt;
        if(x<y) {int tmp = y; y = x; x = tmp;}
        vector<int> pow_x={1}; vector<int> pow_y={1};
        int power = 1;
        bool flag_x = false, flag_y = false;
        if(y==1) flag_y = true;
        if(x==1) flag_x = true;
        while(1){
            int pow_number_x = pow(x, power);
            int pow_number_y = pow(y, power);
            if(!flag_x && pow_number_x < bound) pow_x.push_back(pow_number_x);
            else flag_x = true;
            if(!flag_y && pow_number_y < bound) pow_y.push_back(pow_number_y);
            else flag_y = true;
            if(flag_x && flag_y) break;
            power ++;
        }
        
        for(int a: pow_x){
            if(a>=bound) break;
            for(int b: pow_y){
                if(a+b>bound) break;
                if(find(begin(rlt), end(rlt),a+b) == rlt.end()) rlt.push_back(a+b);
            }
        }
        
        return rlt;
    }
};