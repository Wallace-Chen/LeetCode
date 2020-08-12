class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> rlt;
        int index=0, len=intervals.size();
        while(index<len && intervals[index][1] < newInterval[0]){
            rlt.push_back(intervals[index++]);
        }
        while(index<len && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        rlt.push_back({newInterval[0], newInterval[1]});
        while(index<len) rlt.push_back(intervals[index++]);
        
        return rlt;
    }
};