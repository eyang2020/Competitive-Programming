#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    // let dp[i][j] represent the length of the LCS of s[0..i-1] and t[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs;
    while(m && n) {
        if(s[m-1] == t[n-1]) {
            lcs += s[m-1];
            m--;
            n--;
        }
        else if(dp[m-1][n] > dp[m][n-1]) {
            m--;
        }
        else {
            n--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
}
