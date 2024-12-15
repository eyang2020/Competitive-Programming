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
    return ((0 <= y && y < n) && (0 <= x && x< m));
}

pair<int, int> bfs(vector<vector<char>> grid, pair<int, int > startPoint) {
    int n = grid.size(), m = grid[0].size(), resPart1 = 0, resPart2 = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m));
    q.push(startPoint);
    while(!q.empty()) {
        auto f = q.front();
        q.pop();
        int y1 = f.first, x1 = f.second;
        vis[y1][x1] = true;
        if(grid[y1][x1] == '9') {
            resPart2++;
        } 
        for(int i=0;i<4;i++) {
            int y2 = y1 + dy[i], x2 = x1 + dx[i];
            if(inBounds(n, m, y2, x2) && !vis[y2][x2] && (grid[y2][x2] - '0') == (grid[y1][x1] - '0') + 1) {
                q.push({y2, x2});
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '9' && vis[i][j]) {
                resPart1++;
            }
        }
    }
    return {resPart1, resPart2};
}

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> startPoints;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '0') {
                startPoints.push_back({i, j});
            }
        }
    }
    int res = 0;
    for(auto p : startPoints) {
        res += bfs(grid, p).first;
    }
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> startPoints;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '0') {
                startPoints.push_back({i, j});
            }
        }
    }
    int res = 0;
    for(auto p : startPoints) {
        res += bfs(grid, p).second;
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
