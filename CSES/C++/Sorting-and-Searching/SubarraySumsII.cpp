#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	ll sum = 0;
	ll res = 0;
	map<ll, int> mp;
	for(int i=0;i<n;i++) {
		ll x;
		cin >> x;
		sum += x;
		if(sum == k) res++;
		res += mp[sum - k];
		mp[sum]++;
	}
	cout << res << endl;
}
