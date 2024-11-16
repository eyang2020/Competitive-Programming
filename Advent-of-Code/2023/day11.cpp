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

int getManhattanDistance(int y1, int x1, int y2, int x2) {
    return abs(y2 - y1) + abs(x2 - x1);
}

ll getManhattanDistanceWithExpansion(vector<vector<char>> grid, int y1, int x1, int y2, int x2) {
    int n = grid.size(), m = grid[0].size();
    int numEmptyRows = 0, numEmptyCols = 0;
    // Count number of empty rows between [y1, y2]
    int lo = min(y1, y2), hi = max(y1, y2);
    for(int i=lo;i<=hi;i++) {
        bool isEmptyRow = true;
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                isEmptyRow = false;
                break;
            }
        }
        if(isEmptyRow) {
            numEmptyRows++;
        }
    }
    // Count number of empty cols between [x1, x2]
    lo = min(x1, x2), hi = max(x1, x2);
    for(int i=lo;i<=hi;i++) {
        bool isEmptyCol = true;
        for(int j=0;j<n;j++) {
            if(grid[j][i] == '#') {
                isEmptyCol = false;
                break;
            }
        }
        if(isEmptyCol) {
            numEmptyCols++;
        }
    }
    ll multiplier = 1000000;
    ll res = abs(y2 - y1) - numEmptyRows + (numEmptyRows * multiplier) + abs(x2 - x1) - numEmptyCols + (numEmptyCols * multiplier);
    return res;
}

void part1(vector<vector<char>> grid) {
    int numRows = grid.size(), numCols = grid[0].size();
    vector<int> emptyRowIdx, emptyColIdx;
    for(int i=0;i<numRows;i++) {
        bool isEmptyRow = true;
        for(int j=0;j<numCols;j++) {
            if(grid[i][j] == '#') {
                isEmptyRow = false;
                break;
            }
        }
        if(isEmptyRow) {
            emptyRowIdx.push_back(i);
        }
    }
    for(int i=0;i<numCols;i++) {
        bool isEmptyCol = true;
        for(int j=0;j<numRows;j++) {
            if(grid[j][i] == '#') {
                isEmptyCol = false;
                break;
            }
        }
        if(isEmptyCol) {
            emptyColIdx.push_back(i);
        }
    }
    // Expand grid rows
    for(int i=emptyRowIdx.size()-1;i>=0;i--) {
        string str(numCols, '.');
        vector<char> row(str.begin(), str.end());
        grid.insert(grid.begin() + emptyRowIdx[i], row);
    }
    // Expand grid cols
    for(int i=emptyColIdx.size()-1;i>=0;i--) {
        for(int j=0;j<grid.size();j++) {
            grid[j].insert(grid[j].begin() + emptyColIdx[i], '.');
        }
    }
    // Get all vertices
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> vertices;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                vertices.push_back({i, j});
            }
        }
    }
    // Sum the shortest path distances of each pair of vertices
    int k = vertices.size(), res = 0;
    for(int i=0;i<k;i++) {
        pair<int, int> p1 = vertices[i];
        for(int j=i+1;j<k;j++) {
            pair<int, int> p2 = vertices[j];
            res += getManhattanDistance(p1.first, p1.second, p2.first, p2.second);
        }
    }
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    // Get all vertices
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> vertices;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                vertices.push_back({i, j});
            }
        }
    }
    // Sum the shortest path distances of each pair of vertices
    int k = vertices.size();
    ll res = 0;
    for(int i=0;i<k;i++) {
        pair<int, int> p1 = vertices[i];
        for(int j=i+1;j<k;j++) {
            pair<int, int> p2 = vertices[j];
            res += getManhattanDistanceWithExpansion(grid, p1.first, p1.second, p2.first, p2.second);
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
