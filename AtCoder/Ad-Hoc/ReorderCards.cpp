#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

void compress(vector<int> &v) {
    int n = v.size();
    map<int, int> mp;
    for(int i=0;i<n;i++) mp[v[i]] = 0;
    int cnt = 1;
    for(auto &p : mp) p.second = cnt++;
    for(int i=0;i<n;i++) v[i] = mp[v[i]];
}

int main() {
    IOS
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    compress(x);
    compress(y);
    for(int i=0;i<n;i++) printf("%d %d\n", x[i], y[i]);
    return 0;
}
