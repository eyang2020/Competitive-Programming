#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void part1(vector<vector<int>> a) {
	int mx = 0;
	for(auto v : a) {
		int sum = 0;
		for(auto x : v) {
			sum += x;
		}
		mx = max(mx, sum);
	}
	cout << mx << endl;
}

void part2(vector<vector<int>> a) {
	vector<int> b;
	for(auto v : a) {
		int sum = 0;
		for(auto x : v) {
			sum += x;
		}
		b.push_back(sum);
	}
	sort(b.rbegin(), b.rend());
	int res = b[0] + b[1] + b[2];
	cout << res << endl;
}

int main() {
	IOS
	string s;
	vector<vector<int>> a;
	vector<int> cur;
	while(getline(cin, s)) {
		if(s == "") {
			a.push_back(cur);
			cur.clear();
		}
		else {
			int x = stoi(s);
			cur.push_back(x);
		}
	}
	if(cur.size() > 0) {
		a.push_back(cur);
	}
	part1(a);
	part2(a);
}
