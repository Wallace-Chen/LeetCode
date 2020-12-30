class Solution {
public:
    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=-1, tripNow=0, tripLeft=0;
        for(int i=0;i<gas.size();i++){
            gas[i] -= cost[i];
            if(index>=0){ // has a possible candidate
                tripNow += gas[i];
                if(tripNow<0){ // the possible candidate failed
                    index = -1; // reset index
                    tripLeft += tripNow; // add to tripLeft variable
                    tripNow = 0;
                }
            }else{
                if(gas[i]>=0){ // this is a possible candidate
                    index = i;
                    tripNow += gas[i];
                }else tripLeft += gas[i];
            }
        }
        
        if(tripNow+tripLeft>=0) return index;
        else return -1;
    }
    */
    // We can take advantage of the fact that the solution is unique if any. Thus we use total_surplus to help us check if there's any solution, and use surplus to help us check if any gas station could be the solution.
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // Note this method use the fact that: if total_surplus>=0, then there must be unique solution. And if we start from i, with gas[i]-cost[i]>0, and we cannot reach to the point j, then any point between [i,j] cannot be a solution.
        int total_surplus = 0, surplus=0, index=0;
        for(int i=0;i<gas.size();i++){
            surplus += (gas[i]-cost[i]);
            total_surplus += (gas[i]-cost[i]);
            if(surplus<0){
                index = i + 1; // i can not be the solution since gas[i] - cost[i] must be negative
                surplus = 0;
            }
        }
        return (total_surplus>=0) ? index  : -1;
    }
};
