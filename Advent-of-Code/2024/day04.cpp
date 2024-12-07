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

int countOccurances(string s, string target) {
    int res = 0;
    size_t pos = 0;
    while((pos = s.find(target, pos)) != string::npos) {
        res++;
        pos += target.length();
    }
    return res;
}

int getTotalCount(vector<vector<char>> grid, string target) {
    int res = 0, n = grid.size(), m = grid[0].size();
    // Horizontal
    for(int i=0;i<n;i++) {
        string row(grid[i].begin(), grid[i].end());
        res += countOccurances(row, target);
    }
    // Vertical
    for(int i=0;i<m;i++) {
        string col = "";
        for(int j=0;j<n;j++) {
            col += grid[j][i];
        }
        res += countOccurances(col, target);
    }
    // Major diagonal - Lower half
    for(int i=n-1;i>=1;i--) {
        string diag = "";
        int y = i, x = 0;
        while(y < n && x < m) {
            diag += grid[y++][x++];
        }
        //cout << diag << endl;
        res += countOccurances(diag, target);
    }
    // Major diagonal - Upper half
    for(int j=0;j<m;j++) {
        string diag = "";
        int y = 0, x = j;
        while(y < n && x < m) {
            diag += grid[y++][x++];
        }
        //cout << diag << endl;
        res += countOccurances(diag, target);
    }
    // Minor diagonal - Lower half
    for(int i=n-1;i>=1;i--) {
        string diag = "";
        int y = i, x = m - 1;
        while(y < n && x >= 0) {
            diag += grid[y++][x--];
        }
        //cout << diag << endl;
        res += countOccurances(diag, target);
    }
    // Minor diagonal - Upper half
    for(int j=m-1;j>=0;j--) {
        string diag = "";
        int y = 0, x = j;
        while(y < n && x >= 0) {
            diag += grid[y++][x--];
        }
        //cout << diag << endl;
        res += countOccurances(diag, target);
    }
    return res;
}

bool ok(vector<vector<char>> grid, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    if(0 <= y - 1 && y + 1 < n && 0 <= x - 1 && x + 1 < m) {
        string majorDiag{grid[y-1][x-1], grid[y][x], grid[y+1][x+1]};
        string minorDiag{grid[y-1][x+1], grid[y][x], grid[y+1][x-1]};
        if((majorDiag == "SAM" || majorDiag == "MAS") && (minorDiag == "SAM" || minorDiag == "MAS")) {
            return true;
        }
    }
    return false;
}

void part1(vector<vector<char>> grid) {
    int res = 0;
    res += getTotalCount(grid, "XMAS");
    res += getTotalCount(grid, "SAMX");
    cout << res << endl;
}

void part2(vector<vector<char>> grid) {
    int res = 0, n = grid.size(), m = grid[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(ok(grid, i, j)) {
                res++;
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
