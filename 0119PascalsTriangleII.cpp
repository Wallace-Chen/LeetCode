class Solution {
public:
    vector<int> getRow(int rowIndex) { // pt[i] = pt[i-1] * (n+1-i)/i
        vector<int> pt(rowIndex+1, 1);
        for(int i=1;i<=rowIndex;i++){
            double tmp = (i<=rowIndex/2 ? (double)pt[i-1]*(double)(rowIndex+1-i)/i : pt[rowIndex-i]);
            pt[i] = (int)tmp;
        }
        return pt;
    }
};
