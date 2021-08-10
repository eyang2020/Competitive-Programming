#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	// let dp[x] represent the minimum number of moves to reduce x to 0
	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++) {
		for(auto c : to_string(i)) {
			dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
		}
	}
	cout << dp[n] << endl;
}
