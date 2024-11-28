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

int countVisitedTiles(vector<vector<char>> grid, pair<char, pair<int, int>> startTile) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    queue<pair<char, pair<int, int>>> rays;
    map<char, vector<vector<bool>>> mp;
    vector<vector<bool>> vis(n, vector<bool>(m));
    mp['N'] = vis;
    mp['S'] = vis;
    mp['E'] = vis;
    mp['W'] = vis;
    rays.push(startTile); 
    while(!rays.empty()) {
        auto ray = rays.front();
        rays.pop();
        char dir = ray.first;
        int i = ray.second.first, j = ray.second.second;
        if(dir == 'N') i--;
        else if(dir == 'S') i++;
        else if(dir == 'E') j++;
        else j--;
        if(0 <= i && i < n && 0 <= j && j < m) {
            if(grid[i][j] == '.') {
                if(!mp[dir][i][j]) {
                    mp[dir][i][j] = true;
                    rays.push({dir, {i, j}});
                }
            }
            else if(grid[i][j] == '/') {
                char nextDir = dir;
                if(dir == 'N') {
                    nextDir = 'E';
                }
                else if(dir == 'S') {
                    nextDir = 'W';
                }
                else if(dir == 'E') {
                    nextDir = 'N';
                }
                else {
                    nextDir = 'S';
                }
                if(!mp[nextDir][i][j]) {
                    mp[nextDir][i][j] = true;
                    rays.push({nextDir, {i, j}});
                }
            }
            else if(grid[i][j] == '\\') {
                char nextDir = dir;
                if(dir == 'N') {
                    nextDir = 'W';
                }
                else if(dir == 'S') {
                    nextDir = 'E';
                }
                else if(dir == 'E') {
                    nextDir = 'S';
                }
                else {
                    nextDir = 'N';
                }
                if(!mp[nextDir][i][j]) {
                    mp[nextDir][i][j] = true;
                    rays.push({nextDir, {i, j}});
                }
            }
            else if(grid[i][j] == '-') {
                if(dir == 'N') {
                    if(!mp['E'][i][j]) {
                        mp['E'][i][j] = true;
                        rays.push({'E', {i, j}});
                    }
                    if(!mp['W'][i][j]) {
                        mp['W'][i][j] = true;
                        rays.push({'W', {i, j}});
                    }
                }
                else if(dir == 'S') {
                    if(!mp['E'][i][j]) {
                        mp['E'][i][j] = true;
                        rays.push({'E', {i, j}});
                    }
                    if(!mp['W'][i][j]) {
                        mp['W'][i][j] = true;
                        rays.push({'W', {i, j}});
                    }
                }
                else if(dir == 'E') {
                    if(!mp[dir][i][j]) {
                        mp[dir][i][j] = true;
                        rays.push({dir, {i, j}});
                    }
                }
                else {
                    if(!mp[dir][i][j]) {
                        mp[dir][i][j] = true;
                        rays.push({dir, {i, j}});
                    }
                }
            }
            else if(grid[i][j] == '|') {
                if(dir == 'N') {
                    if(!mp[dir][i][j]) {
                        mp[dir][i][j] = true;
                        rays.push({dir, {i, j}});
                    }
                }
                else if(dir == 'S') {
                    if(!mp[dir][i][j]) {
                        mp[dir][i][j] = true;
                        rays.push({dir, {i, j}});
                    }
                }
                else if(dir == 'E') {
                    if(!mp['N'][i][j]) {
                        mp['N'][i][j] = true;
                        rays.push({'N', {i, j}});
                    }
                    if(!mp['S'][i][j]) {
                        mp['S'][i][j] = true;
                        rays.push({'S', {i, j}});
                    }
                }
                else {
                    if(!mp['N'][i][j]) {
                        mp['N'][i][j] = true;
                        rays.push({'N', {i, j}});
                    }
                    if(!mp['S'][i][j]) {
                        mp['S'][i][j] = true;
                        rays.push({'S', {i, j}});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            res += (mp['N'][i][j] || mp['S'][i][j] || mp['E'][i][j] || mp['W'][i][j]);
        }
    }
    return res;
}

void part1(vector<vector<char>> grid) {
    // Have to start at [0, -1] for when there is a mirror at [0, 0]
    cout << countVisitedTiles(grid, {'E', {0, -1}}) << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    for(int i=0;i<n;i++) {
        res = max(res, countVisitedTiles(grid, {'E', {i, -1}}));
        res = max(res, countVisitedTiles(grid, {'W', {i, m}}));
    }
    for(int j=0;j<m;j++) {
        res = max(res, countVisitedTiles(grid, {'N', {n, j}}));
        res = max(res, countVisitedTiles(grid, {'S', {-1, j}}));
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
