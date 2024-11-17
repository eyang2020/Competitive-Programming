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

bool fixSmudgeShowsReflection(string s1, string s2) {
    int n = s1.size(), cnt = 0;
    for(int i=0;i<n;i++) {
        if(s1[i] != s2[i]) {
            cnt++;
        }
    }
    return (cnt == 1);
}

void part1(vector<vector<string>> horizontalGrids, vector<vector<string>> verticalGrids) {
    ll res = 0;
    int z = horizontalGrids.size();
    for(int i=0;i<z;i++) {
        vector<string> horizontalGrid = horizontalGrids[i];
        vector<string> verticalGrid = verticalGrids[i];
        int n = horizontalGrid.size(), m = horizontalGrid[0].size();
        // Try all horizontal splits
        for(int k=0;k<n-1;k++) {
            int turns = min(k + 1, n - k - 1);
            bool ok = true;
            for(int j=0;j<turns;j++) {
                if(horizontalGrid[k-j] != horizontalGrid[k+j+1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                res += 100 * (k + 1);
                break;
            }
        }
        // Try all vertical splits
        for(int k=0;k<m-1;k++) {
            int turns = min(k + 1, m - k - 1);
            bool ok = true;
            for(int i=0;i<turns;i++) {
                if(verticalGrid[k-i] != verticalGrid[k+i+1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                res += (k + 1);
                break;
            }
        }
    }
    cout << res << endl;
}

void part2(vector<vector<string>> horizontalGrids, vector<vector<string>> verticalGrids) {
    ll res = 0;
    int z = horizontalGrids.size();
    for(int i=0;i<z;i++) {
        vector<string> horizontalGrid = horizontalGrids[i];
        vector<string> verticalGrid = verticalGrids[i];
        int n = horizontalGrid.size(), m = horizontalGrid[0].size();
        // Try all horizontal splits
        for(int k=0;k<n-1;k++) {
            int turns = min(k + 1, n - k - 1);
            int smudges = 0;
            int temp = 0;
            bool ok = true;
            for(int j=0;j<turns;j++) {
                if(horizontalGrid[k-j] != horizontalGrid[k+j+1]) {
                    if(fixSmudgeShowsReflection(horizontalGrid[k-j], horizontalGrid[k+j+1])) {
                        smudges++;
                        temp += 100 * (k + 1);
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok && smudges == 1) {
                res += temp;
            }
        }
        // Try all vertical splits
        for(int k=0;k<m-1;k++) {
            int turns = min(k + 1, m - k - 1);
            int smudges = 0;
            int temp = 0;
            bool ok = true;
            for(int i=0;i<turns;i++) {
                if(verticalGrid[k-i] != verticalGrid[k+i+1]) {
                    if(fixSmudgeShowsReflection(verticalGrid[k-i], verticalGrid[k+i+1])) {
                        smudges++;
                        temp += (k + 1);
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok && smudges == 1) {
                res += temp;
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<vector<string>> horizontalGrids, verticalGrids;
    vector<string> horizontalGrid, verticalGrid;
    while(getline(cin, s)) {
        if(s.length() == 0) {
            horizontalGrids.push_back(horizontalGrid);
            horizontalGrid = {};
        }
        else {
            horizontalGrid.push_back(s);
        }
    }
    if(horizontalGrid.size() > 0) {
        horizontalGrids.push_back(horizontalGrid);
    }
    for(vector<string> horizontalGrid : horizontalGrids) {
        int n = horizontalGrid.size(), m = horizontalGrid[0].size();
        vector<string> verticalGrid(m, "");
        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                verticalGrid[j] += horizontalGrid[i][j];
            }
        }
        verticalGrids.push_back(verticalGrid);
        verticalGrid = {};
    }
    //part1(horizontalGrids, verticalGrids);
    part2(horizontalGrids, verticalGrids);
    return 0;
}
