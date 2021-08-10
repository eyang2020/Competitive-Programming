#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	// this is the 0-1 knapsack problem
	int n, x;
	cin >> n >> x;
	vector<int> prices(n), pages(n);
	for(int i=0;i<n;i++) cin >> prices[i];
	for(int i=0;i<n;i++) cin >> pages[i];
	// let dp[i][j] represent the maximum number of pages among first i books, with total price <= j
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=x;j++) {
			dp[i][j] = dp[i-1][j];
			// try buying the (i-1)th book
			int left = j - prices[i-1];
			if(left >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][left] + pages[i-1]);
			}
		}
	}
	cout << dp[n][x] << endl;
}
