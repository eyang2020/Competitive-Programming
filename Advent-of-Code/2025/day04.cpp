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

bool inBounds(int n, int m, int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int countTouching(vector<vector<char>> grid, int x, int y) {
    int n = grid.size(), m = grid[0].size(), cnt = 0;
    for(int i=0;i<8;i++) {
        int nextX = x + dxWithDiag[i], nextY = y + dyWithDiag[i];
        if(inBounds(n, m, nextX, nextY) && grid[nextX][nextY] == '@') {
            cnt++;
        }
    }
    return cnt;
}

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '@') {
                int cnt = countTouching(grid, i, j);
                if(cnt < 4) {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    bool done = false;
    while(!done) {
        done = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '@') {
                    int cnt = countTouching(grid, i, j);
                    if(cnt < 4) {
                        grid[i][j] = '.';
                        res++;
                        done = false;
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    string s;
    vector<vector<char>> grid;
    while(getline(cin, s)) {
        vector<char> v(s.begin(), s.end());
        grid.push_back(v);
    }
    IOS
    part1(grid);
    part2(grid);
    return 0;
}
