#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

int main() {
    IOS
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if(sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int half = sum / 2;
    // let dp[i][j] represent the number of ways to form sum j using numbers [0..i]
    vector<vector<int>> dp(n, vector<int>(half + 1));
    dp[0][0] = 1;
    for(int j=0;j<=half;j++) {
        for(int i=1;i<n;i++) {
            if(j >= i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i-1][j-i]) % MOD;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][half] << endl;
    return 0;
}
