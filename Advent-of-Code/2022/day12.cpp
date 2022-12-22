#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<vector<int>> bfs(vector<vector<char>> grid, pair<int, int> s_coords) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    q.push(s_coords);
    dist[s_coords.first][s_coords.second] = 0;
    while(!q.empty()) {
        pair<int, int> cur_coords = q.front();
        int x1 = cur_coords.first, y1 = cur_coords.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                if((grid[x2][y2] - grid[x1][y1] <= 1) && (dist[x1][y1] + 1 < dist[x2][y2])) {
                    dist[x2][y2] = dist[x1][y1] + 1;
                    q.push({x2, y2});
                }
            }
        }
    }
    return dist;
}

void part1(vector<vector<char>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    // get location of S and E
    pair<int, int> s_coords, e_coords;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'S') {
                s_coords = {i, j};
            }
            else if(grid[i][j] == 'E') {
                e_coords = {i, j};
            }
        }
    }
    // replace S with a and E with z
    grid[s_coords.first][s_coords.second] = 'a';
    grid[e_coords.first][e_coords.second] = 'z';
    // 0-1 BFS
    vector<vector<int>> dist = bfs(grid, s_coords);
    cout << dist[e_coords.first][e_coords.second] << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    // get locations of all a's, and S
    pair<int, int> e_coords;
    vector<pair<int, int>> lowest_coords;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'S') {
                grid[i][j] = 'a';
                lowest_coords.push_back({i, j});
            }
            else if(grid[i][j] == 'E') {
                grid[i][j] = 'z';
                e_coords = {i, j};
            }
            else if(grid[i][j] == 'a') {
                lowest_coords.push_back({i, j});
            }
        }
    }
    // run 0-1 BFS from each location in lowest_coords
    int mn = INF;
    for(auto p : lowest_coords) {
        vector<vector<int>> dist = bfs(grid, p);
        mn = min(mn, dist[e_coords.first][e_coords.second]);
    }
    cout << mn << endl;
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
