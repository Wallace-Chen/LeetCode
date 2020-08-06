class Solution {
public:
    /*
    int trap(vector<int>& height) {
        int len = height.size(), water = 0;
        if(len<=1) return 0;
        vector<int> leftmax(len), rightmax(len);
        leftmax[0] = height[0]; rightmax[len-1] = height[len-1];
        for(int i = 1;i<len;i++){
            leftmax[i] = max(height[i], leftmax[i-1]);
            rightmax[len-1-i] = max(height[len-1-i] , rightmax[len-i]);
        }
        for(int i = 0; i<len;i++){
            water += min(leftmax[i], rightmax[i]) - height[i];
        }
        return water;
    }
    */
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                cout << st.top() << ", " << current << endl;
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                cout << distance * bounded_height << endl;
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};