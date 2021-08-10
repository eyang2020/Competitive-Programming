#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> grid[i][j];
		}
	}
	// let dp[i][j] represent the total number of ways to reach coordinates (i, j) from (0, 0)
	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(grid[i][j] == '.') {
				if(i - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
				}
				if(j - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
				}
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n-1][n-1] << endl;
}
