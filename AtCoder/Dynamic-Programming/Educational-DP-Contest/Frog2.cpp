#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    // let dp[i] represent the minimum cost to reach stone i from stone 0
    vector<int> h(n), dp(n, 1e9);
    for(int i=0;i<n;i++) cin >> h[i];
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=1;j<=k;j++) {
            if(i + j < n) dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
        }
    }
    cout << dp[n-1] << endl;
}
