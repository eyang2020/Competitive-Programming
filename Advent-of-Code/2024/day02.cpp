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

bool isSafe(vector<int> level) {
    int m = level.size();
    bool increasing = true, decreasing = true, ok = true;
    for(int j=1;j<m;j++) {
        if(level[j] <= level[j-1]) {
            increasing = false;
        }
        if(level[j] >= level[j-1]) {
            decreasing = false;
        }
        int diff = abs(level[j] - level[j-1]);
        if(diff < 1 || diff > 3) {
            ok = false;
        }
    }
    ok = ok && (increasing ^ decreasing);
    return ok;
}

void part1(vector<vector<int>> v) {
    int n = v.size();
    int res = 0;
    for(int i=0;i<n;i++) {
        vector<int> level = v[i];
        res += isSafe(level);
    }
    cout << res << endl;
}

void part2(vector<vector<int>> v) {
    int n = v.size();
    int res = 0;
    for(int i=0;i<n;i++) {
        vector<int> level = v[i];
        int m = level.size();
        for(int j=0;j<m;j++) {
            vector<int> next = level;
            next.erase(next.begin() + j);
            if(isSafe(next)) {
                res++;
                break;
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    vector<vector<int>> v;
    string s;
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, " ");
        vector<int> b;
        for(auto x : a) {
            b.push_back(stoi(x));
        }
        v.push_back(b);
    }
    part1(v);
    part2(v);
    return 0;
}
