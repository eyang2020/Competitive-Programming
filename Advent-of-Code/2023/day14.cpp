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

void tiltNorth(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<m;i++) {
        for(int j=1;j<n;j++) {
            if(grid[j][i] == 'O') {
                int k = j - 1;
                while(k >= 0 && grid[k][i] == '.') {
                    k--;
                }
                if(k + 1 >= 0 && grid[k+1][i] == '.') {
                    grid[j][i] = '.';
                    grid[k+1][i] = 'O';
                }
            }
        }
    }
}

void tiltWest(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(grid[i][j] == 'O') {
                int k = j - 1;
                while(k >= 0 && grid[i][k] == '.') {
                    k--;
                }
                if(k + 1 >= 0 && grid[i][k+1] == '.') {
                    grid[i][j] = '.';
                    grid[i][k+1] = 'O';
                }
            }
        }
    }
}

void tiltSouth(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<m;i++) {
        for(int j=n-2;j>=0;j--) {
            if(grid[j][i] == 'O') {
                int k = j + 1;
                while(k < n && grid[k][i] == '.') {
                    k++;
                }
                if(k - 1 < n && grid[k-1][i] == '.') {
                    grid[j][i] = '.';
                    grid[k-1][i] = 'O';
                }
            }
        }
    }
}

void tiltEast(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<n;i++) {
        for(int j=m-2;j>=0;j--) {
            if(grid[i][j] == 'O') {
                int k = j + 1;
                while(k < m && grid[i][k] == '.') {
                    k++;
                }
                if(k - 1 < m && grid[i][k-1] == '.') {
                    grid[i][j] = '.';
                    grid[i][k-1] = 'O';
                }
            }
        }
    }
}

void cycle(vector<vector<char>> &grid) {
    tiltNorth(grid);
    tiltWest(grid);
    tiltSouth(grid);
    tiltEast(grid);
}

int getTotalLoad(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'O') {
                res += n - i;
            }
        }
    }
    return res;
}

string gridToString(vector<vector<char>> grid) {
    string res;
    int n = grid.size();
    for(int i=0;i<n;i++) {
        vector<char> v = grid[i];
        string s(v.begin(), v.end());
        res += s;
    }
    return res;
}

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    tiltNorth(grid);

    // [DEBUG] Print grid
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    cout << getTotalLoad(grid) << endl;
}

void part2(vector<vector<char>> grid) {
    vector<vector<char>> gridCopy = grid;
    int n = grid.size(), m = grid[0].size();
    map<string, int> mp;
    int cyclesRemaining = 1e9;
    int numCycles = 0;
    while(true) {
        cycle(grid);
        numCycles++;
        cyclesRemaining--;
        string gridStr = gridToString(grid);
        if(mp.count(gridStr)) {
            int cycleLength = numCycles - mp[gridStr];
            cyclesRemaining %= cycleLength;
            break;
        }
        mp[gridStr] = numCycles;
    }
    for(int i=0;i<cyclesRemaining;i++) {
       cycle(grid);
    }
    cout << getTotalLoad(grid) << endl;
}

int main() {
    IOS
    string s;
    vector<vector<char>> grid;
    while(getline(cin, s)) {
        vector<char> v(s.begin(), s.end());
        grid.push_back(v);
    }
    part1(grid);
    part2(grid);
    return 0;
}
