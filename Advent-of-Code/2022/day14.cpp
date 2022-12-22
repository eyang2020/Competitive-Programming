#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1000;
const int M = 1000;

const int dy[3] = {1, 1, 1};
const int dx[3] = {0, -1, 1};

bool can_rest(vector<vector<char>> &grid) {
	int y = 0, x = 500;
	if(grid[y][x] == 'o') {
		return false;
	}
	bool done = false;
	while(!done) {
		done = true;
		for(int i=0;i<3;i++) {
			int next_y = y + dy[i], next_x = x + dx[i];
			if(next_y < N && next_x >= 0 && next_x < M) {
				if(grid[next_y][next_x] == '.') {
					y = next_y, x = next_x;
					done = false;
					break;
				}
			}
			else {
				return false;
			}
		}
	}
	grid[y][x] = 'o';
	return true;
}

void part1(vector<vector<char>> grid) {
	int res = 0;
	while(can_rest(grid)) {
		res++;
	}
	cout << res << endl;
}

void part2(vector<vector<char>> grid, int y_max) {
	int y_floor = y_max + 2;
	for(int i=0;i<M;i++) {
		grid[y_floor][i] = '#';
	}
	int res = 0;
	while(can_rest(grid)) {
		res++;
	}
	cout << res << endl;
}

int main() {
	// read input
	vector<vector<pair<int, int>>> coords;
	string s;
	while(getline(cin, s)) {
		vector<pair<int, int>> cur;
		int pos = 0;
		string token;
		string delim = " -> ";
		while((pos = s.find(delim)) != std::string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + delim.length());
			pos = token.find(",");
			cur.push_back({stoi(token.substr(0, pos)), stoi(token.substr(pos + 1))});
		}
		pos = s.find(",");
		cur.push_back({stoi(s.substr(0, pos)), stoi(s.substr(pos + 1))});
		coords.push_back(cur);
	}
	// build the grid
	int y_max = 0;
	vector<vector<char>> grid(N, vector<char>(M, '.'));
	for(auto v : coords) {
		int n = v.size();
		for(int i=0;i<n-1;i++) {
			int y1 = v[i].second, x1 = v[i].first;
			int y2 = v[i+1].second, x2 = v[i+1].first;
			y_max = max(y_max, max(y1, y2));
			if(x1 > x2) {
				swap(x1, x2);
			}
			if(y1 > y2) {
				swap(y1, y2);
			}
			for(int j=y1;j<=y2;j++) {
				for(int k=x1;k<=x2;k++) {
					grid[j][k] = '#';
				}
			}
		}
	}
	part1(grid);
	part2(grid, y_max);
}
