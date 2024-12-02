#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 700;
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

struct Hole {
    string dir;
    int len;
    string color;
};

void floodfill(vector<vector<char>> &grid, vector<vector<bool>> &vis, int curY, int curX) {
    int n = grid.size(), m = grid[0].size();
    if(curY < 0 || curY >= n || curX < 0 || curX >= m) {
        return;
    }
    if(vis[curY][curX]) {
        return;
    }
    if(grid[curY][curX] == '#') {
        return;
    }
    grid[curY][curX] = '#';
    vis[curY][curX] = true;
    floodfill(grid, vis, curY - 1, curX);
    floodfill(grid, vis, curY + 1, curX);
    floodfill(grid, vis, curY, curX - 1);
    floodfill(grid, vis, curY, curX + 1);
}

bool isSurrounded(vector<vector<char>> grid, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    bool up = false, down = false, left = false, right = false;
    for(int i=y-1;i>=0;i--) {
        if(grid[i][x] == '#') {
            up = true;
            break;
        }
    }
    if(!up) return false;
    for(int i=y+1;i<n;i++) {
        if(grid[i][x] == '#') {
            down = true;
            break;
        }
    }
    if(!down) return false;
    for(int i=x-1;i>=0;i--) {
        if(grid[y][i] == '#') {
            left = true;
            break;
        }
    }
    if(!left) return false;
    for(int i=x+1;i<m;i++) {
        if(grid[y][i] == '#') {
            right = true;
            break;
        }
    }
    return right;
}

void part1(vector<Hole> holes) {
    int n = holes.size(), res = 0;
    vector<vector<char>> grid(N, vector<char>(N, '.'));
    pair<int, int> pos = {N / 2, N / 2};
    grid[pos.first][pos.second] = '#';
    for(int i=0;i<n;i++) {
        Hole hole = holes[i];
        for(int j=0;j<hole.len;j++) {
            if(hole.dir == "U") {
                pos.first = pos.first - 1;
            }
            else if(hole.dir == "D") {
                pos.first++;
            }
            else if(hole.dir == "L") {
                pos.second = pos.second - 1;
            }
            else {
                pos.second++;
            }
            grid[pos.first][pos.second] = '#';
        }
    }
    // Find any interior point surrounded by holes on all sides. Use it as the starting point for floodfill.
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    bool done = false;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(isSurrounded(grid, i, j)) {
                floodfill(grid, vis, i, j);
                done = true;
                break;
            }
        }
        if(done) break;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            //cout << grid[i][j];
            res += (grid[i][j] == '#');
        }
        //cout << endl;
    }
    cout << res << endl;
}

void part2() {

}

int main() {
    IOS
    string s;
    vector<Hole> holes;
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, " ");
        Hole hole = {a[0], stoi(a[1]), a[2]};
        holes.push_back(hole);
    }
    part1(holes);
    part2();
    return 0;
}
