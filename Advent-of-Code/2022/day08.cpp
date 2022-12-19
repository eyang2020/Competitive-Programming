#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool is_visible(vector<vector<char>> grid, int x, int y) {
	int n = grid.size();
	int m = grid[0].size();
	vector<int> max_heights(4, 0);
	for(int i=x-1;i>=0;i--) {
		max_heights[0] = max(max_heights[0], grid[i][y] - '0');
	}
	for(int i=x+1;i<n;i++) {
		max_heights[1] = max(max_heights[1], grid[i][y] - '0');
	}
	for(int i=y-1;i>=0;i--) {
		max_heights[2] = max(max_heights[2], grid[x][i] - '0');
	}
	for(int i=y+1;i<m;i++) {
		max_heights[3] = max(max_heights[3], grid[x][i] - '0');
	}
	for(int i=0;i<4;i++) {
		if(max_heights[i] < (grid[x][y] - '0')) {
			return true;
		}
	}
	return false;
}

int get_scenic_score(vector<vector<char>> grid, int x, int y) {
	int n = grid.size();
	int m = grid[0].size();
	int res = 1;
	int idx = -1;
	for(int i=x-1;i>=0;i--) {
		if(grid[x][y] <= grid[i][y]) {
			idx = i;
			break;
		}
	}
	res *= ((idx == -1) ? x : x - idx);
	idx = -1;
	for(int i=x+1;i<n;i++) {
		if(grid[x][y] <= grid[i][y]) {
			idx = i;
			break;
		}
	}
	res *= ((idx == -1) ? n - x - 1 : idx - x);
	idx = -1;
	for(int i=y-1;i>=0;i--) {
		if(grid[x][y] <= grid[x][i]) {
			idx = i;
			break;
		}
	}
	res *= ((idx == -1) ? y : y - idx);
	idx = -1;
	for(int i=y+1;i<m;i++) {
		if(grid[x][y] <= grid[x][i]) {
			idx = i;
			break;
		}
	}
	res *= ((idx == -1) ? m - y - 1 : idx - y);
	return res;
}

void part1(vector<vector<char>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	int res = 0;
	for(int i=1;i<n-1;i++) {
		for(int j=1;j<m-1;j++) {
			if(is_visible(grid, i, j)) {
				res++;
			}
		}
	}
	cout << res + 2 * n + 2 * m - 4 << endl;
}

void part2(vector<vector<char>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	int res = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			res = max(res, get_scenic_score(grid, i, j));
		}
	}
	cout << res << endl;
}

int main() {
	vector<vector<char>> grid;
	string s;
	while(getline(cin, s)) {
		vector<char> row(s.begin(), s.end());
		grid.push_back(row);
	}
	part1(grid);
	part2(grid);
}
