#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	ll prefix = 0, res = 0;
	map<ll, int> cnt;
	cnt[0] = 1;
	for(int i=0;i<n;i++) {
		ll x;
		cin >> x;
		prefix = (((prefix + x) % n) + n) % n;
		res += cnt[prefix]++;
	}
	cout << res << endl;
}
