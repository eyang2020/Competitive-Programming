class Solution {
public:
    int res;
    int sessionTime;
    vector<int> tasks;
    vector<int> sessions;
    void dfs(int i) {
        if(sessions.size() >= res) {
            return;
        }    
        if(tasks.size() == i) {
            res = min(res, (int)sessions.size());
            return;
        }
        for(int j=0;j<sessions.size();j++) {
            if(sessions[j] + tasks[i] <= sessionTime) {
                sessions[j] += tasks[i];
                dfs(i + 1);
                sessions[j] -= tasks[i];
            }
        }
        sessions.push_back(tasks[i]);
        dfs(i + 1);
        sessions.pop_back();
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->tasks = tasks;
        this->sessionTime = sessionTime;
        res = tasks.size();
        dfs(0);
        return res;
    }
};
