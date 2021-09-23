#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

int main() {
    IOS
    int n;
    while(cin >> n) {
        vector<pair<int, int>> pos(n);
        for(int i=0,x;i<n;i++) {
            cin >> x;
            pos[i] = {x, i};
        }
        sort(pos.begin(), pos.end());
        vector<bool> vis(n);
        int res = 0;
        for(int i=0;i<n;i++) {
            if(vis[i] || pos[i].second == i) continue;
            int cycleSize = 0;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = pos[j].second;
                cycleSize++;
            }
            if(cycleSize > 0) res += cycleSize - 1;
        }
        cout << res << endl;
    }
    return 0;
}

