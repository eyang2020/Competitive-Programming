
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<pair<string, int>> a;

void part1() {
	int x = 0, y = 0;
	for(auto [dir, val] : a) {
		if(dir == "forward") x += val;
		else if(dir == "up") y -= val;
		else y += val;
	}
	cout << x * y << endl;
}

void part2() {
	int x = 0, y = 0, aim = 0;
	for(auto [dir, val] : a) {
		if(dir == "forward") {
			x += val;
			y += aim * val;
		}
		else if(dir == "up") aim -= val;
		else aim += val;
	}
	cout << x * y << endl;
}

int main() {
	string s;
	while(getline(cin, s)) {
		string dir = s.substr(0, s.find(" "));
		int val = stoi(s.substr(s.find(" ") + 1));
		a.push_back({dir, val});
	}
	part1();
	part2();
}
