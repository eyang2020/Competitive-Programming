#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	// let dp[x] represent the number of ways sum x can be made using numbers 1-6
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=6&&i-j>=0;j++) {
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	cout << dp[n] << endl;
}
