class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students[0].size();
        vector<int> idx(m);
        for(int i=0;i<m;i++) idx[i] = i;
        int res = 0;
        do {
            int cur = 0;
            for(int i=0;i<m;i++) {
                int score = 0;
                for(int j=0;j<n;j++) if(students[idx[i]][j] == mentors[i][j]) score++;
                cur += score;
            }
            res = max(res, cur);
        } while(next_permutation(idx.begin(), idx.end()));
        return res;
    }
};
