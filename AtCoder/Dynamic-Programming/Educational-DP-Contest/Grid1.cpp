#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin >> grid[i][j];
        }
    }
    // let dp[i][j] represent the number of paths from (1, 1) to (i, j)
    vector<vector<ll>> dp(h+1, vector<ll>(w+1));
    dp[1][1] = 1;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            char c = grid[i-1][j-1];
            if(c == '#') {
                dp[i][j] = 0;
            }
            else {
                if(i - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if(j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[h][w] << endl;
}
