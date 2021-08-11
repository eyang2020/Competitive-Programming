#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	// let dp[i][j] represent the minimum number of moves to change a[:i] to b[:j]
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
	dp[0][0] = 0;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if(i > 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			}
			if(j > 0) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
			}
			if(i > 0 && j > 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
			}
		}
	}
	cout << dp[n][m] << endl;
}
