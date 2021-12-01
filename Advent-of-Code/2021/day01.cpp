
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void part1(vector<int> a) {
	int n = a.size(), last = a[0], res = 0;
	for(int i=1;i<n;i++) {
		if(a[i] > last) {
			res++;
		}
		last = a[i];
	}
	cout << res << endl;
}

void part2(vector<int> a) {
	int n = a.size(), last = a[0] + a[1] + a[2], sum = last, res = 0;
	for(int i=3;i<n;i++) {
		sum = sum + a[i] - a[i-3];
		if(sum > last) {
			res++;
		}
		last = sum;
	}
	cout << res << endl;
}

int main() {
	vector<int> a;
	int x;
	while(cin >> x) {
		a.push_back(x);
	}
	part1(a);
	part2(a);
}
