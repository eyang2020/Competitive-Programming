#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	// this is the 0-1 knapsack problem
	int n;
	cin >> n;
	int mxSum = n * 1000;
	vector<int> x(n);
	for(int i=0;i<n;i++) {
		cin >> x[i];
	}
	// let dp[i][j] represent whether sum j can be made using the first i numbers
	vector<vector<bool>> dp(n + 1, vector<bool>(mxSum + 1));
	dp[0][0] = true;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=mxSum;j++) {
			dp[i][j] = dp[i-1][j];
			int left = j - x[i-1];
			if(left >= 0 && dp[i-1][left]) {
				dp[i][j] = true;
			}
		}
	}
	vector<int> sums;
	for(int i=1;i<=mxSum;i++) {
		if(dp[n][i]) {
			sums.push_back(i);
		}
	}
	cout << sums.size() << endl;
	for(auto sum : sums) cout << sum << ' ';
	cout << endl;
}
