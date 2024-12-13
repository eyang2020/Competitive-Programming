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

bool inBounds(int n, int m, pair<int, int> p) {
    int y = p.first, x = p.second;
    return ((0 <= y && y < n) && (0 <= x && x < m));
}

struct Comparator {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
};

void part1(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<char>> res(n, vector<char>(m, '.'));
    map<char, vector<pair<int, int>>> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] != '.') {
                mp[grid[i][j]].push_back({i, j});
            }   
        }
    }
    for(auto p : mp) {
        char c = p.first;
        vector<pair<int, int>> v = p.second;
        sort(v.begin(), v.end(), Comparator());
        int z = v.size();
        for(int i=0;i<z;i++) {
            for(int j=i+1;j<z;j++) {
                pair<int, int> p1 = v[i], p2 = v[j], p3 = p1, p4 = p2;
                int y1 = p1.first, x1 = p1.second, y2 = p2.first, x2 = p2.second;
                int diffY = abs(y2 - y1), diffX = abs(x2 - x1);
                if(diffY == 0) {
                    p3 = {y1, x1 - diffX};
                    p4 = {y2, x2 + diffX};
                }
                else if(diffX == 0) {
                    if(y1 < y2) {
                        p3 = {y1 - diffY, x1};
                        p4 = {y2 + diffY, x2};
                    }
                    else {
                        p3 = {y1 + diffY, x1};
                        p4 = {y2 - diffY, x2};
                    }
                }
                else {
                    if(y1 < y2) {
                        //cout << y2 << ' ' << x2 << endl;
                        //cout << y1 << ' ' << x1 << endl;
                        p3 = {y1 - diffY, x1 - diffX};
                        p4 = {y2 + diffY, x2 + diffX};
                    }
                    else {
                        p3 = {y1 + diffY, x1 - diffX};
                        p4 = {y2 - diffY, x2 + diffX};
                    }
                }
                if(inBounds(n, m, p3)) {
                    res[p3.first][p3.second] = '#';
                }
                if(inBounds(n, m, p4)) {
                    res[p4.first][p4.second] = '#';
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            //cout << res[i][j];
            if(res[i][j] == '#') {
                cnt++;
            }
        }
        //cout << endl;
    }
    cout << cnt << endl;
}

void part2(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<char>> res(n, vector<char>(m, '.'));
    map<char, vector<pair<int, int>>> mp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] != '.') {
                mp[grid[i][j]].push_back({i, j});
            }   
        }
    }
    for(auto p : mp) {
        char c = p.first;
        vector<pair<int, int>> v = p.second;
        sort(v.begin(), v.end(), Comparator());
        int z = v.size();
        for(int i=0;i<z;i++) {
            for(int j=i+1;j<z;j++) {
                pair<int, int> p1 = v[i], p2 = v[j], p3 = p1, p4 = p2;
                res[p1.first][p1.second] = '#';
                res[p2.first][p2.second] = '#'; 
                int y1 = p1.first, x1 = p1.second, y2 = p2.first, x2 = p2.second;
                int diffY = abs(y2 - y1), diffX = abs(x2 - x1);
                if(diffY == 0) {
                    p3 = {y1, x1 - diffX};
                    while(inBounds(n, m, p3)) {
                        res[p3.first][p3.second] = '#';
                        p3 = {p3.first, p3.second - diffX};
                    }
                    p4 = {y2, x2 + diffX};
                    while(inBounds(n, m, p4)) {
                        res[p4.first][p4.second] = '#';
                        p4 = {p4.first, p4.second + diffX};
                    }
                }
                else if(diffX == 0) {
                    if(y1 < y2) {
                        p3 = {y1 - diffY, x1};
                        while(inBounds(n, m, p3)) {
                            res[p3.first][p3.second] = '#';
                            p3 = {p3.first - diffY, p3.second};
                        }
                        p4 = {y2 + diffY, x2};
                        while(inBounds(n, m, p4)) {
                            res[p4.first][p4.second] = '#';
                            p4 = {p4.first + diffY, p4.second};
                        }
                    }
                    else {
                        p3 = {y1 + diffY, x1};
                        while(inBounds(n, m, p3)) {
                            res[p3.first][p3.second] = '#';
                            p3 = {p3.first + diffY, p3.second};
                        }
                        p4 = {y2 - diffY, x2};
                        while(inBounds(n, m, p4)) {
                            res[p4.first][p4.second] = '#';
                            p4 = {p4.first - diffY, p4.second};
                        }
                    }
                }
                else {
                    if(y1 < y2) {
                        //cout << y2 << ' ' << x2 << endl;
                        //cout << y1 << ' ' << x1 << endl;
                        p3 = {y1 - diffY, x1 - diffX};
                        while(inBounds(n, m, p3)) {
                            res[p3.first][p3.second] = '#';
                            p3 = {p3.first - diffY, p3.second - diffX};
                        }
                        p4 = {y2 + diffY, x2 + diffX};
                        while(inBounds(n, m, p4)) {
                            res[p4.first][p4.second] = '#';
                            p4 = {p4.first + diffY, p4.second + diffX};
                        }
                    }
                    else {
                        p3 = {y1 + diffY, x1 - diffX};
                        while(inBounds(n, m, p3)) {
                            res[p3.first][p3.second] = '#';
                            p3 = {p3.first + diffY, p3.second - diffX};
                        }
                        p4 = {y2 - diffY, x2 + diffX};
                        while(inBounds(n, m, p4)) {
                            res[p4.first][p4.second] = '#';
                            p4 = {p4.first - diffY, p4.second + diffX};
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            //cout << res[i][j];
            if(res[i][j] == '#') {
                cnt++;
            }
        }
        //cout << endl;
    }
    cout << cnt << endl;
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
