class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int num = points.size();
        if(num<3) return num;
        unordered_map<string, int> hash_table={};
        int ret = 0;
        for(int i=0;i<num;i++){
            hash_table.clear();
            int cnt = 1; // important here, should not be 0. in case [[1,1],[1,1],[1,1]]
            int duplicates = 0;
            for(int j=i+1;j<num;j++){
                int slpy = points[j][1] - points[i][1];
                int slpx = points[j][0] - points[i][0];
                if(!slpy && !slpx) { // meets the same point, add 1 on every slopes
                    duplicates ++;
                    continue;
                }
                if(!slpx){ //vertical line, set it to (0,x)
                    slpy = points[j][0];
                }else if(!slpy){ // horizontal line, set it to (y, 0)
                    slpx = points[j][1];
                }
                else if(slpy && slpx) coPrime(slpx, slpy); // not horizontal or vertical, co-prime them and then store
                string s = to_string(slpx) + "_" + to_string(slpy);
                if(hash_table.find(s) == hash_table.end()) hash_table[s] = 1;
                hash_table[s] ++;
                cnt = max(cnt, hash_table[s]);
            }
            ret = max(ret, cnt+duplicates);
        }
        return ret;
    }
    
    void coPrime(int &num1, int &num2){
        int abs1 = abs(num1), abs2 = abs(num2);
        int small = min(abs1, abs2);
        for(int i=small;i>1;i--){
            if(abs1%i == 0 && abs2%i==0){
                abs1/=i;
                abs2/=i;
            }
        }
        num1 = ((num1<0) == (num2<0)) ? abs1 : -abs1;
        num2 = abs2;
    }
};
/*
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int num = points.size();
        if(num<3) return num;
        // since pair cannot be hashed, either we use the map instead of unordered_map, or we mannually impelement a hashi function for unordered_map. But. both are quite slow.
        unordered_map<pair<int,int>, int, hash_pair> hash_table={};
        // map<pair<int,int>, int> hash_table={};
        int ret = 0;
        for(int i=0;i<num;i++){
            hash_table.clear();
            int cnt = 1; // important here, should not be 0. in case [[1,1],[1,1],[1,1]]
            int duplicates = 0;
            for(int j=i+1;j<num;j++){
                int slpy = points[j][1] - points[i][1];
                int slpx = points[j][0] - points[i][0];
                if(!slpy && !slpx) { // meets the same point, add 1 on every slopes
                    duplicates ++;
                    continue;
                }
                if(!slpx){ //vertical line, set it to (0,x)
                    slpy = points[j][0];
                }else if(!slpy){ // horizontal line, set it to (y, 0)
                    slpx = points[j][1];
                }
                else if(slpy && slpx) coPrime(slpx, slpy); // not horizontal or vertical, co-prime them and then store
                if(hash_table.find({slpx, slpy}) == hash_table.end()) hash_table[{slpx, slpy}] = 1;
                hash_table[{slpx, slpy}] ++;
                cnt = max(cnt, hash_table[{slpx, slpy}]);
            }
            ret = max(ret, cnt+duplicates);
        }
        return ret;
    }
    
    void coPrime(int &num1, int &num2){
        int abs1 = abs(num1), abs2 = abs(num2);
        int small = min(abs1, abs2);
        for(int i=small;i>1;i--){
            if(abs1%i == 0 && abs2%i==0){
                abs1/=i;
                abs2/=i;
            }
        }
        num1 = ((num1<0) == (num2<0)) ? abs1 : -abs1;
        num2 = abs2;
    }
private:
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
};
*/
