#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    // let dp[i] represent the minimum cost to jump from stone 0 to stone i
    vector<int> h(n), dp(n, 1e9);
    for(int i=0;i<n;i++) cin >> h[i];
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        if(i + 1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        if(i + 2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
    }
    cout << dp[n-1] << endl;
}
