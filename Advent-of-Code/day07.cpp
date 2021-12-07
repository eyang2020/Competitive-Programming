#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> a;

void part1() {
	int n = (int)a.size();
	sort(a.begin(), a.end());
	int med = a[n/2];
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum += abs(a[i] - med);
	}
	cout << sum << endl;
}

void part2() {

}

int main() {
	string s;
	getline(cin, s);
	int pos = 0;
	string token;
	string delim = ",";
	while ((pos = s.find(delim)) != string::npos) {
		token = s.substr(0, pos);
		a.push_back(stoi(token));
		s.erase(0, pos + delim.length());
	}
	a.push_back(stoi(s));
	part1();
	part2();
}
