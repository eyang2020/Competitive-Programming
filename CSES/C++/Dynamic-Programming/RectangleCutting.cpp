#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int w, h;
	cin >> w >> h;
	// let dp[i][j] represent the minimum number of cuts to turn a i x j rectangle into squares
	vector<vector<int>> dp(w + 1, vector<int>(h + 1, 1e9));
	for(int i=0;i<=w;i++) {
		for(int j=0;j<=h;j++) {
			if(i == j) {
				dp[i][j] = 0;
			}
			else {
				for(int k=1;k<i;k++) {
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
				}
				for(int k=1;k<j;k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
				}
			}
		}
	}
	cout << dp[w][h] << endl;
}
