
class Solution {
public:
    vector<vector<int> > rlt;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        combine(n, k, tmp);
        return rlt;
    }
    
    void combine(int n, int k, vector<int>& com) {
        int start = 1;
        if(com.size()>0) start = com.back() + 1;
        for(int i = start;i<=n;i++){
            com.push_back(i);
            if(k==1) rlt.push_back(com);
            else combine(n, k-1, com);
            com.pop_back();
        }
    }
};

/*
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k > n) return vector<vector<int>>(); // 空的二维数组
        if(k == 0) return vector<vector<int>>(1, vector<int>()); // 包含了1个空一维数组的二维数组
        vector<vector<int>> res = combine(n - 1, k - 1);
        for(int i = 0; i < res.size(); i++) res[i].push_back(n);
        for(auto &cb: combine(n - 1, k)) res.push_back(cb);
        return res;
    }
};
*/
/*
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
*/
