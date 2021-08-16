#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> a[i][j];
        }
    }
    // let dp[i][j] represent the maximum score on day i ending with activity j
    vector<vector<int>> dp(n, vector<int>(3));
    for(int i=0;i<3;i++) dp[0][i] = a[0][i];
    for(int i=1;i<n;i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i][2];
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}
