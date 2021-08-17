#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
int V = 1e5 + 5;

int main() {
    int n;
    ll W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> w[i] >> v[i];
    // let dp[i] represent the lowest possible weight for value i
    vector<ll> dp(V, 1e18);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=V-1;j>=0;j--) {
            if(dp[j] + w[i] <= W) {
                dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
            }
        }
    }
    for(int i=V-1;i>=0;i--) {
        if(dp[i] != 1e18) {
            cout << i << endl;
            break;
        }
    }
}
