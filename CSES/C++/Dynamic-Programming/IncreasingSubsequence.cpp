#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> dp;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		// for LIS with non-strict increasing, change to upper_bound
		auto it = lower_bound(dp.begin(), dp.end(), x);
		if(it == dp.end()) {
			dp.push_back(x);
		}
		else {
			*it = x;
		}
	}
	cout << dp.size() << endl;
}
