#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	ll x;
	cin >> n >> x;
	vector<pair<ll, int>> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	int l, r;
	for(int i=0;i<n-2;i++) {
		l = i + 1;
		r = n - 1;
		while(l < r) {
			ll sum = a[i].first + a[l].first + a[r].first;
			if(sum == x) {
				cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << endl;
				return 0;
			}
			else if(sum < x) l++;
			else r--;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
