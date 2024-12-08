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

vector<char> directions = {'^', 'v', '<', '>'};

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

void dfs(vector<vector<char>> &grid, map<char, vector<vector<int>>> &vis, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    int nextY = y, nextX = x;
    char nextDir = grid[y][x];
    vis[grid[y][x]][y][x]++;
    if(grid[y][x] == '^') {
        if(y - 1 >= 0 && grid[y-1][x] == '#') {
            if(x + 1 < m && grid[y][x+1] == '#') {
                nextY++;
                nextDir = 'v';
            }
            else {
                nextX++;
                nextDir = '>';
            }
        }
        else {
            nextY--;
        }
    }
    else if(grid[y][x] == 'v') {
        if(y + 1 < n && grid[y+1][x] == '#') {
            if(x - 1 >= 0 && grid[y][x-1] == '#') {
                nextY--;
                nextDir = '^';
            }
            else {
                nextX--;
                nextDir = '<';
            }
        }
        else {
            nextY++;
        }
    }
    else if(grid[y][x] == '<') {
        if(x - 1 >= 0 && grid[y][x-1] == '#') {
            if(y - 1 >= 0 && grid[y-1][x] == '#') {
                nextX++;
                nextDir = '>';
            }
            else {
                nextY--;
                nextDir = '^';
            }
        }
        else {
            nextX--;
        }
    }
    else if(grid[y][x] == '>') {
        if(x + 1 < m && grid[y][x+1] == '#') {
            if(y + 1 < n && grid[y+1][x] == '#') {
                nextX--;
                nextDir = '<';
            }
            else {
                nextY++;
                nextDir = 'v';
            }
        }
        else {
            nextX++;
        }
    }
    if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m && vis[nextDir][nextY][nextX] < 2) {
        grid[y][x] = '.';
        grid[nextY][nextX] = nextDir;
        dfs(grid, vis, nextY, nextX);
    }
}

bool isCyclic(vector<vector<char>> grid, map<char, vector<vector<int>>> vis) {
    int n = grid.size(), m = grid[0].size();
    for(char dir : directions) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[dir][i][j] >= 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

void part1(vector<vector<char>> grid) {
    int res = 0, n = grid.size(), m = grid[0].size();
    map<char, vector<vector<int>>> vis;
    for(char dir : directions) {
        vis[dir] = vector<vector<int>>(n, vector<int>(m));
    }
    pair<int, int> startPoint = {};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '^') {
                startPoint = {i, j};
            }
        }
    }
    dfs(grid, vis, startPoint.first, startPoint.second);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            bool ok = false;
            for(char dir : directions) {
                ok = ok || (vis[dir][i][j] >= 1);
            }
            res += ok;
        }
    }
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    int res = 0, n = grid.size(), m = grid[0].size();
    pair<int, int> startPoint = {};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '^') {
                startPoint = {i, j};
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '.') {
                vector<vector<char>> tempGrid = grid;
                tempGrid[i][j] = '#';
                map<char, vector<vector<int>>> vis;
                for(char dir : directions) {
                    vis[dir] = vector<vector<int>>(n, vector<int>(m));
                }
                dfs(tempGrid, vis, startPoint.first, startPoint.second);
                res += isCyclic(tempGrid, vis);
            }
        }
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
    part1(grid);
    part2(grid);
    return 0;
}
