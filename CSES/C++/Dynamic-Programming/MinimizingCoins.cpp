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
	// let dp[x] represent the minimum number of coins needed to make sum x 
	vector<int> dp(x + 1, 1e9);
	dp[0] = 0;
	for(int i=1;i<=x;i++) {
		for(auto c : coins) {
			if(i - c >= 0) {
				dp[i] = min(dp[i], dp[i-c] + 1);
			}
		}
	}
	cout << ((dp[x] == 1e9) ? -1 : dp[x]) << endl;
}
