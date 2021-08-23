class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<4001> p(1);
        for(auto row : mat) {
            bitset<4001> temp;
            for(auto x : row) {
                temp |= (p << x);
            }
            swap(p, temp);
        }
        int res = 1e9;
        for(int i=1;i<=4000;i++) {
            if(p[i]) {
                res = min(res, abs(target - i));
            }
        }
        return res;
    }
};
