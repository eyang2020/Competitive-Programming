
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1000;
int grid[N][N];
vector<vector<pair<int, int>>> points;

void part1() {
	for(auto v : points) {
		int x1 = v[0].first, y1 = v[0].second;
		int x2 = v[1].first, y2 = v[1].second;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		if(x1 == x2) {
			for(int i=y1;i<=y2;i++) {
				grid[i][x1]++;
			}
		}
		else if(y1 == y2) {
			for(int i=x1;i<=x2;i++) {
				grid[y1][i]++;
			}
		}	
	}
	int cnt = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(grid[i][j] >= 2) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

void part2() {
	for(auto v : points) {
		int x1 = v[0].first, y1 = v[0].second;
		int x2 = v[1].first, y2 = v[1].second;
		int m = (y2 - y1) / (x2 - x1);
		if(x1 == x2) {
			if(y1 > y2) swap(y1, y2);
			for(int i=y1;i<=y2;i++) {
				grid[i][x1]++;
			}
		}
		else if(y1 == y2) {
			if(x1 > x2) swap(x1, x2);
			for(int i=x1;i<=x2;i++) {
				grid[y1][i]++;
			}
		}	
		else if(abs(m) == 1) {
			if(m < 0) {
				if(x1 > x2) {
					swap(x1, x2);
				}
				if(y1 > y2) {
					swap(y1, y2);
				}
				for(int i=x1,j=y2;i<=x2;i++,j--) {
					grid[j][i]++;
				}
			}
			else {
				if(x1 > x2) {
					swap(x1, x2);
				}
				if(y1 > y2) {
					swap(y1, y2);
				}
				for(int i=x1,j=y1;i<=x2;i++,j++) {
					grid[j][i]++;
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(grid[i][j] >= 2) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main() {
	string s;
	while(getline(cin, s)) {
		int pos = 0, x1, y1, x2, y2;
		string token;
		string delim = " -> ";
		pos = s.find(delim);
		token = s.substr(0, pos);
		s.erase(0, pos + delim.length());
		delim = ",";
		pos = token.find(delim);
		x1 = stoi(token.substr(0, pos));
		token.erase(0, pos + delim.length());
		y1 = stoi(token);
		pos = s.find(delim);
		x2 = stoi(s.substr(0, pos));
		s.erase(0, pos + delim.length());
		y2 = stoi(s);
		vector<pair<int, int>> v;
		v.push_back({x1, y1});
		v.push_back({x2, y2});
		points.push_back(v);
	}
	part1();
	part2();
}
