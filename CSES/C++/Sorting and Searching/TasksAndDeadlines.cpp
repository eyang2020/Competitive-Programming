#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> events;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, b});
    }
    ll res = 0;
    sort(events.begin(), events.end());
    ll cur = 0;
    for(auto e : events) {
        cur += e.first;
        res += e.second - cur;
    }
    cout << res << endl;
}
