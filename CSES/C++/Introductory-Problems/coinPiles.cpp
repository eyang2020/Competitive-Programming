#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		ll x = 2 * a - b, y = 2 * b - a;
		cout << ((x >= 0 && x % 3 == 0 && y >= 0 && y % 3 == 0) ? "YES" : "NO") << endl;
	}
}
