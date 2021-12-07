#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll cnt[10];

void part1() {
	for(int day=1;day<=80;day++) {
		cnt[7] += cnt[0];
		cnt[9] += cnt[0];
		cnt[0] = 0;
		for(int i=0;i<9;i++) {
			cnt[i] = cnt[i+1];
			cnt[i+1] = 0;
		}
	}
	ll sum = 0;
	for(int i=0;i<9;i++) {
		sum += cnt[i];
	}
	cout << sum << endl;
}

void part2() {
	for(int day=1;day<=256;day++) {
		cnt[7] += cnt[0];
		cnt[9] += cnt[0];
		cnt[0] = 0;
		for(int i=0;i<9;i++) {
			cnt[i] = cnt[i+1];
			cnt[i+1] = 0;
		}
	}
	ll sum = 0;
	for(int i=0;i<9;i++) {
		sum += cnt[i];
	}
	cout << sum << endl;
}

int main() {
	string s;
	getline(cin, s);
	int pos = 0;
	string token;
	string delim = ",";
	while ((pos = s.find(delim)) != string::npos) {
		token = s.substr(0, pos);
		cnt[stoi(token)]++;
		s.erase(0, pos + delim.length());
	}
	cnt[stoi(s)]++;
	part1();
	part2();
}
