class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b) { return (a[0]<b[0]); }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > rlt;
        if(intervals.size()==0) return rlt;
        sort(intervals.begin(), intervals.end(), mycmp);
        rlt.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>& last = rlt[rlt.size()-1];
            if(intervals[i][0]<=last[1] ){ // can merge with the last vector in the rlt
                last[1] = max(last[1], intervals[i][1]);
            }else rlt.push_back(intervals[i]);
        }
        return rlt;
    }
};