#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	stack<pair<int, int>> stk;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		while(!stk.empty() && stk.top().first >= x) stk.pop();
		cout << (stk.empty() ? 0 : stk.top().second) << ' ';
		stk.push({x, i + 1});
	}
}
