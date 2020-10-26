class Solution {
public:
    /*
    int minimumTotal(vector<vector<int>>& triangle) { // top-down method
        int num = triangle.size();
        if(num==0) return 0;
        vector<int> sums(num, INT_MAX);
        sums[0] = triangle[0][0];
        for(int j=1;j<num;j++){
            sums[j] = sums[j-1] + triangle[j][j];
            for(int i=j-1;i>0;i--){
                exchange(sums[i], min(sums[i-1],sums[i])+triangle[j][i] );
            }
            sums[0] += triangle[j][0];
        }
        return *min_element(sums.begin(), sums.end());
    }
    */
    
    int minimumTotal(vector<vector<int>>& triangle) { // bottom up solution
        int s = triangle.size();
        if(s==0) return 0;
        vector<int> sums = triangle[s-1];
        for(int i=s-2;i>=0;i--){
            for(int j=0;j<=i;j++)
                sums[j] = min(sums[j], sums[j+1]) + triangle[i][j];
        }
        return sums[0];
    }
};
