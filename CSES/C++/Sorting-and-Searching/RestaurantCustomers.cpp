#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<pair<int, bool>> events;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, true});
        events.push_back({b, false});
    }
    sort(events.begin(), events.end());
    int res = 0, cur = 0;
    for(auto p : events) {
        cur += p.second ? 1 : -1;
        res = max(res, cur);
    }
    cout << res << endl;
}
