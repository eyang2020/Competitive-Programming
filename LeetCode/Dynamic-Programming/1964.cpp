class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> lis;
        for(int i=0;i<n;i++) {
            int x = obstacles[i];
            if(lis.empty() || lis[lis.size()-1] <= x) {
                lis.push_back(x);
                obstacles[i] = lis.size();
            }
            else {
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
                lis[idx] = x;
                obstacles[i] = idx + 1;
            }
        }
        return obstacles;
    }
};
