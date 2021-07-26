#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> events;
    map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
    int rooms = 0;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, {-1, i}}); // in
        events.push_back({b, {1, i}}); // out
    }
    sort(events.begin(), events.end());
    for(auto p : events) {
        int kind = p.second.first;
        int idx = p.second.second;
        if(kind == -1) {
            if(pq.empty()) mp[idx] = ++rooms;
            else {
                mp[idx] = pq.top();
                pq.pop();
            }
        }
        else pq.push(mp[idx]);
    }
    cout << rooms << endl;
    for(auto p : mp) cout << p.second << ' ';
    cout << endl;
}
