#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int i=0;i<n;i++) cin >> coins[i];
	// let dp[x] represent the total number of ways to form sum x with given coins
	vector<int> dp(x + 1);
	dp[0] = 1;
	for(int i=1;i<=x;i++) {
		for(auto c : coins) {
			if(i - c >= 0) {
				dp[i] = (dp[i] + dp[i-c]) % MOD;
			}
		}
	}
	cout << dp[x] << endl;
}
