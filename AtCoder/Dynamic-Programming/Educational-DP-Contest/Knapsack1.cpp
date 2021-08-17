#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> w[i] >> v[i];
    // let dp[i][j] represent the maximum attainable value from first i weights with total weight j
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            if(w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
}
