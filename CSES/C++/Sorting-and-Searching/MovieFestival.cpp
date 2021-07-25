#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({b, a});
    }
    sort(events.begin(), events.end());
    int res = 0, last = 0;
    for(auto p : events) {
        if(p.second >= last) {
            last = p.first;
            res++;
        }
    }
    cout << res << endl;
}
