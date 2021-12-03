
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<string> a;

void part1() {
	int n = (int)a.size();
	int m = (int)a[0].length();
	string epsilon, gamma;
	for(int i=0;i<m;i++) {
		int cnt0 = 0;
		for(int j=0;j<n;j++) {
			if(a[j][i] == '0') cnt0++;
		}
		int cnt1 = n - cnt0;
		if(cnt0 < cnt1) {
			gamma += '1';
			epsilon += '0';
		}
		else {
			gamma += '0';
			epsilon += '1';
		}
	}
	int res = bitset<32>(gamma).to_ulong() * bitset<32>(epsilon).to_ulong();
	cout << res << endl;
}

static string calc(int n, int m, int prio, multiset<string> ms) {
	for(int i=0;i<m;i++) {
		int cnt0 = 0;
		for(auto x : ms) {
			if(x[i] == '0') cnt0++;
		}
		int cnt1 = (int)ms.size() - cnt0;
		if(prio == 1) {
			if(cnt0 <= cnt1) {
				for(auto x : ms) {
					if(x[i] == '0') {
						if(ms.size() > 1) ms.erase(x);
					}
				}
			}
			else {
				for(auto x : ms) {
					if(x[i] == '1') {
						if(ms.size() > 1) ms.erase(x);
					}
				}
			}
		}
		else {
			if(cnt0 <= cnt1) {
				for(auto x : ms) {
					if(x[i] == '1') {
						if(ms.size() > 1) ms.erase(x);
					}
				}
			}
			else {
				for(auto x : ms) {
					if(x[i] == '0') {
						if(ms.size() > 1) ms.erase(x);
					}
				}
			}
		}
	}
	return *ms.begin();
}

void part2() {
	int n = (int)a.size();
	int m = (int)a[0].length();
	multiset<string> pool1, pool2;
	for(int i=0;i<n;i++) {
		pool1.insert(a[i]);
		pool2.insert(a[i]);
	}
	int res = bitset<32>(calc(n, m, 1, pool1)).to_ulong() * bitset<32>(calc(n, m, 0, pool2)).to_ulong();
	cout << res << endl;
}

int main() {
	string s;
	while(getline(cin, s)) a.push_back(s);
	part1();
	part2();
}
