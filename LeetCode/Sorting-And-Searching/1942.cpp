// 1942. The Number of the Smallest Unoccupied Chair
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, pair<int, int>>> events;
        for(int i=0;i<n;i++) {
            auto v = times[i];
            int start = v[0], end = v[1];
            events.push_back({v[0], {1, i}});
            events.push_back({v[1], {-1, i}});
        }
        sort(events.begin(), events.end());
        map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        int cur = 0;
        int occ = 0;
        for(auto e : events) {
            int num = e.second.second;
            int type = e.second.first;
            
            if(type == 1) {
                if(occ == pq.size()) {
                    mp[num] = cur++;
                }
                else {
                    mp[num] = pq.top();
                    pq.pop();
                }
            }
            else {
                pq.push(mp[num]);
            }
        }
        return mp[targetFriend];
    }
};
