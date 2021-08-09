#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	map<ll, pair<int, int>> mp;
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			mp[a[i] + a[j]] = {i, j};
		}
	}
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			ll sum = a[i] + a[j];
			if(mp.find(x - sum) != mp.end()) {
				pair<int, int> p = mp[x - sum];
				if(p.first != i && p.first != j && p.second != i && p.second != j) {
					cout << (i + 1) << ' ' << (j + 1) << ' ' << (p.first + 1) << ' ' << (p.second + 1) << endl;
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
