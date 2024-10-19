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

bool isNextToSymbol(vector<string> grid, int y, int x) {
    int n = grid.size(), m = grid[0].length();
    for(int i=0;i<8;i++) {
        int nextY = y + dyWithDiag[i], nextX = x + dxWithDiag[i];
        if(nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && grid[nextY][nextX] != '.' && !isdigit(grid[nextY][nextX])) {
            return true;
        }
    }
    return false;
}

int getGearValue(vector<string> grid, int y, int x) {
    int n = grid.size(), m = grid[0].length();
    vector<int> numbers;
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<8;i++) {
        int nextY = y + dyWithDiag[i], nextX = x + dxWithDiag[i];
        if(nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && isdigit(grid[nextY][nextX]) && !vis[nextY][nextX]) {
            string val = string(1, grid[nextY][nextX]);
            vis[nextY][nextX] = true;
            int idx = nextX - 1;
            while(idx >= 0 && isdigit(grid[nextY][idx])) {
                val = grid[nextY][idx] + val;
                vis[nextY][idx] = true;
                idx--;
            }
            idx = nextX + 1;
            while(nextX < m && isdigit(grid[nextY][idx])) {
                val = val + grid[nextY][idx];
                vis[nextY][idx] = true;
                idx++;
            }
            numbers.push_back(stoi(val));
        }
    }
    return (numbers.size() == 2) ? (numbers[0] * numbers[1]) : 0;
}

void part1(vector<string> grid) {
    int n = grid.size(), m = grid[0].length(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            string val = "";
            int l = j;
            bool ok = false;
            while(j < m && isdigit(grid[i][j])) {
                val += grid[i][j];
                j++;
            }
            for(int k=l;k<j;k++) {
                if(isNextToSymbol(grid, i, k)) {
                    ok = true;
                    break;
                }
            }
            if(ok) {
                res += stoi(val);
            }
        }
    }
    cout << res << endl;
}

void part2(vector<string> grid) {
    int n = grid.size(), m = grid[0].length(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '*') {
                res += getGearValue(grid, i, j);
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<string> grid;
    while(getline(cin, s)) {
        grid.push_back(s);
    }
    part1(grid);
    part2(grid);
    return 0;
}
