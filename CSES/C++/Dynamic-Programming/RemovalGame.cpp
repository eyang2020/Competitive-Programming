#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;
const int N = 5005;

vector<ll> a(N);
// let dp[i][j] represent the maximum score of the first player playing on interval [i, j]
vector<vector<ll>> dp(N, vector<ll>(N, -1));

ll solve(int i, int j) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll op1 = a[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
    ll op2 = a[j] + min(solve(i, j - 2), solve(i + 1, j - 1));
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}

int main() {
    IOS
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    solve(0, n - 1);
    cout << dp[0][n-1] << endl;
    return 0;
}
