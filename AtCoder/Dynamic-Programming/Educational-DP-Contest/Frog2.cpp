#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    // let dp[i] represent the minimum cost to jump from stone 0 to stone i
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
