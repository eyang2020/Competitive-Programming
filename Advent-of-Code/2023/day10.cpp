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

bool canMoveUp(char from, char to) {
    map<char, vector<char>> mp = {
        {'|', {'|', '7', 'F', 'S'}},
        {'-', {}},
        {'L', {'|', '7', 'F', 'S'}},
        {'J', {'|', '7', 'F', 'S'}},
        {'7', {}},
        {'F', {}},
        {'.', {}},
        {'S', {'|', '7', 'F'}},
    };
    vector<char> v = mp[from];
    return find(v.begin(), v.end(), to) != v.end();
}

bool canMoveDown(char from, char to) {
    map<char, vector<char>> mp = {
        {'|', {'|', 'L', 'J', 'S'}},
        {'-', {}},
        {'L', {}},
        {'J', {}},
        {'7', {'|', 'L', 'J', 'S'}},
        {'F', {'|', 'L', 'J', 'S'}},
        {'.', {}},
        {'S', {'|', 'L', 'J'}},
    };
    vector<char> v = mp[from];
    return find(v.begin(), v.end(), to) != v.end();
}

bool canMoveLeft(char from, char to) {
    map<char, vector<char>> mp = {
        {'|', {}},
        {'-', {'-', 'L', 'F', 'S'}},
        {'L', {}},
        {'J', {'-', 'L', 'F', 'S'}},
        {'7', {'-', 'L', 'F', 'S'}},
        {'F', {}},
        {'.', {}},
        {'S', {'-', 'L', 'F'}},
    };
    vector<char> v = mp[from];
    return find(v.begin(), v.end(), to) != v.end();
}

bool canMoveRight(char from, char to) {
    map<char, vector<char>> mp = {
        {'|', {}},
        {'-', {'-', 'J', '7', 'S'}},
        {'L', {'-', 'J', '7', 'S'}},
        {'J', {}},
        {'7', {}},
        {'F', {'-', 'J', '7', 'S'}},
        {'.', {}},
        {'S', {'-', 'J', '7'}},
    };
    vector<char> v = mp[from];
    return find(v.begin(), v.end(), to) != v.end();
}

void floodfillToFillLoop(vector<vector<char>> grid, vector<vector<char>> &loop, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    if(y < 0 || y >= n || x < 0 || x >= m || loop[y][x] == 'L') {
        return;
    }
    loop[y][x] = 'L';
    // Up
    if(y - 1 >= 0 && canMoveUp(grid[y][x], grid[y-1][x])) {
        floodfillToFillLoop(grid, loop, y - 1, x);
    }
    // Down
    if(y + 1 < n && canMoveDown(grid[y][x], grid[y+1][x])) {
        floodfillToFillLoop(grid, loop, y + 1, x);
    }
    // Left
    if(x - 1 >= 0 && canMoveLeft(grid[y][x], grid[y][x-1])) {
        floodfillToFillLoop(grid, loop, y, x - 1);
    }
    // Right
    if(x + 1 < m && canMoveRight(grid[y][x], grid[y][x+1])) {
        floodfillToFillLoop(grid, loop, y, x + 1);
    }
}

void floodfillToFillOutside(vector<vector<char>> grid, vector<vector<char>> &loop, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    if(y < 0 || y >= n || x < 0 || x >= m || loop[y][x] == 'L' || loop[y][x] == 'O') {
        return;
    }
    loop[y][x] = 'O';
    for(int i=0;i<4;i++) {
        int nextY = y + dy[i], nextX = x + dx[i];
        floodfillToFillOutside(grid, loop, nextY, nextX);
    }
}

pair<int, int> getStartingPoint(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    pair<int, int> startingPoint;
    bool done = false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'S') {
                startingPoint = {i, j};
                done = true;
            }
            if(done) {
                break;
            }
        }
        if(done) {
            break;
        }
    }
    return startingPoint;
}

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    pair<int, int> startingPoint = getStartingPoint(grid);

    // Find the loop
    vector<vector<char>> loop(n, vector<char>(m, '.'));
    floodfillToFillLoop(grid, loop, startingPoint.first, startingPoint.second);

    // Build dist matrix
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dist[startingPoint.first][startingPoint.second] = 0;
    vis[startingPoint.first][startingPoint.second] = true;
    queue<pair<int, int>> q;
    q.push(startingPoint);
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int y = f.first, x = f.second;
        // Up
        if(y - 1 >= 0 && loop[y-1][x] == 'L' && !vis[y-1][x] && canMoveUp(grid[y][x], grid[y-1][x])) {
            q.push({y - 1, x});
            dist[y-1][x] = dist[y][x] + 1;
            vis[y-1][x] = true;
        }
        // Down
        if(y + 1 < n && loop[y+1][x] == 'L' && !vis[y+1][x] && canMoveDown(grid[y][x], grid[y+1][x])) {
            q.push({y + 1, x});
            dist[y+1][x] = dist[y][x] + 1;
            vis[y+1][x] = true;
        }
        // Left
        if(x - 1 >= 0 && loop[y][x-1] == 'L' && !vis[y][x-1] && canMoveLeft(grid[y][x], grid[y][x-1])) {
            q.push({y, x - 1});
            dist[y][x - 1] = dist[y][x] + 1;
            vis[y][x - 1] = true;
        }
        // Right
        if(x + 1 < m && loop[y][x+1] == 'L' && !vis[y][x+1] && canMoveRight(grid[y][x], grid[y][x+1])) {
            q.push({y, x + 1});
            dist[y][x + 1] = dist[y][x] + 1;
            vis[y][x + 1] = true;
        }
    }

    // Get max dist of points in the loop
    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vis[i][j]) {
                res = max(res, dist[i][j]);
            }
        }
    }
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    pair<int, int> startingPoint = getStartingPoint(grid);

    // Find the loop
    vector<vector<char>> loop(n, vector<char>(m, '.'));
    floodfillToFillLoop(grid, loop, startingPoint.first, startingPoint.second);

    // TODO: Fill in points outside the loop
    for(int i=0;i<n;i++) floodfillToFillOutside(grid, loop, i, 0);
    for(int i=0;i<n;i++) floodfillToFillOutside(grid, loop, i, m - 1);
    for(int j=0;j<m;j++) floodfillToFillOutside(grid, loop, 0, j);
    for(int j=0;j<m;j++) floodfillToFillOutside(grid, loop, n - 1, j);

    // [DEBUG] Print the loop
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << loop[i][j];
        }
        cout << endl;
    }

    // Count number of points enclosed by the loop
    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(loop[i][j] == '.') {
                res++;
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    vector<vector<char>> grid;
    string s;
    while(getline(cin, s)) {
        vector<char> row(s.begin(), s.end());
        grid.push_back(row);
    }
    part1(grid);
    part2(grid);
    return 0;
}
