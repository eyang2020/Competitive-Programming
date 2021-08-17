#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll MOD = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    // let dp[i][j] represent the maximum attainable difference X - Y in the range [i, j]
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i=0;i<n;i++) {
        dp[i][i] = a[i]; 
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;
}
