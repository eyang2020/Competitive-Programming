#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int dxWithDiag[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dyWithDiag[8] = {1, 0, -1, 0, -1, 1, 1, -1};

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll modpow(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    if(x == 0) return 0;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

vector<string> tokenize(string s, string delim) {
    vector<string> tokens;
    int idx = 0, n = delim.length();
    string token;
    while((idx = s.find(delim)) != string::npos) {
        token = s.substr(0, idx);
        tokens.push_back(token);
        s.erase(0, idx + n);
    }
    tokens.push_back(s);
    return tokens;
}

bool inBounds(int n, int m, int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < m);
}

ll getPerimeter(vector<vector<int>> grid2, int y, int x) {
    int n = grid2.size(), m = grid2[0].size();
    ll res = 0;
    int c = grid2[y][x];
    if(y - 1 < 0 || grid2[y-1][x] != c) {
        res++;
    }
    if(y + 1 >= n || grid2[y+1][x] != c) {
        res++;
    }
    if(x - 1 < 0 || grid2[y][x-1] != c) {
        res++;
    }
    if(x + 1 >= m || grid2[y][x+1] != c) {
        res++;
    }
    return res;
}

int getLabel(vector<vector<int>> grid2, int y, int x) {
    int n = grid2.size(), m = grid2[0].size();
    if(inBounds(n, m, y, x)) {
        return grid2[y][x];
    }
    return 0;
}

ll getCorners(vector<vector<int>> grid2, int y, int x) {
    int n = grid2.size(), m = grid2[0].size();
    int c = grid2[y][x];
    ll res = 0;
    vector<vector<pair<int, int>>> neighbors = {{{0, -1}, {-1, -1}, {-1, 0}}, {{0, 1}, {-1, 1}, {-1, 0}}, {{0, -1}, {1, -1}, {1, 0}}, {{1, 0}, {1, 1}, {0, 1}}};
    for(int i=0;i<neighbors.size();i++) {
        int left = getLabel(grid2, y + neighbors[i][0].first, x + neighbors[i][0].second);
        int mid = getLabel(grid2, y + neighbors[i][1].first, x + neighbors[i][1].second);
        int right = getLabel(grid2, y + neighbors[i][2].first, x + neighbors[i][2].second);
        if((left != c && right != c) || (left == c && right == c && mid != c)) {
            res++;
        }
    }
    return res;
}

void floodfill(vector<vector<char>> grid, vector<vector<int>> &grid2, vector<vector<bool>> &vis, int y, int x, int color) {
    int n = grid.size(), m = grid[0].size();
    vis[y][x] = true;
    grid2[y][x] = color;
    for(int i=0;i<4;i++) {
        int nextY = y + dy[i], nextX = x + dx[i];
        if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m && !vis[nextY][nextX] && grid[nextY][nextX] == grid[y][x]) {
            floodfill(grid, grid2, vis, nextY, nextX, color);
        }
    }
}

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), color = 1;
    vector<vector<int>> grid2(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j]) {
                floodfill(grid, grid2, vis, i, j, color);
                color++;
            }
        }
    }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << grid2[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    map<int, pair<ll, ll>> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int c = grid2[i][j];
            mp[c] = {mp[c].first + getPerimeter(grid2, i, j), mp[c].second + 1};
        }
    }
    ll res = 0;
    for(auto p : mp) {
        //cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
        res += p.second.first * p.second.second;
    }
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), color = 1;
    vector<vector<int>> grid2(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j]) {
                floodfill(grid, grid2, vis, i, j, color);
                color++;
            }
        }
    }
    map<int, pair<ll, ll>> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int c = grid2[i][j];
            mp[c] = {mp[c].first + getCorners(grid2, i, j), mp[c].second + 1};
        }
    }
    ll res = 0;
    for(auto p : mp) {
        //cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
        res += p.second.first * p.second.second;
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<vector<char>> grid;
    while(getline(cin, s)) {
        vector<char> row(s.begin(), s.end());
        grid.push_back(row);
    }
    //part1(grid);
    part2(grid);
    return 0;
}
