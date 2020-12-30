class Solution {
public:
    /*
    int candy(vector<int>& ratings) { // two scans, and take the max
        int length = ratings.size(), total=0;
        vector<int> left2right(length, 1), right2left(length, 1);
        for(int i=1;i<length;i++){
            if(ratings[i]>ratings[i-1]) left2right[i] = left2right[i-1] + 1;
        }
        for(int i=length-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) right2left[i] = right2left[i+1] + 1;
        }
        for(int i=0;i<length;i++){
            total += max(left2right[i], right2left[i]);
        }
        return total;
    }
    */
    int candy(vector<int>& ratings) { // a smarter solution
        int length = ratings.size(), total=1;
        if(length==0) return 0;
        int up=0, down=0, peak=0; // up: continuous climbing levels
        for(int i=1;i<length;i++){
            if(ratings[i]>ratings[i-1]){
                up++;
                down = 0;
                peak = up+1;
                total += peak;
            }else if(ratings[i]==ratings[i-1]){
                up = down = 0;
                peak=1;
                total += peak;
            }else{
                down++;
                up = 0;
                total += down + (peak<=down ? 1 : 0);
            }
        }
        return total;
    }
};
