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

ll getPathLength(string dir, map<string, pair<string, string>> mp, string startingNode) {
    string cur = startingNode;
    ll res = 0;
    int idx = 0;
    int n = dir.length();
    while(true) {
        if(cur[2] == 'Z') {
            break;
        }
        if(dir[idx] == 'L') {
            cur = mp[cur].first;
        }
        else {
            cur = mp[cur].second;
        }
        idx = (idx + 1) % n;
        res++;
    }
    return res;
}

void part1(string dir, map<string, pair<string, string>> mp) {
    ll res = getPathLength(dir, mp, "AAA");
    cout << res << endl;
}

void part2(string dir, map<string, pair<string, string>> mp) {
   // High level idea: for each pair of XXA --> XXZ, find its length. The answer is the LCM of these path lengths.
    map<string, ll> multiples;
    for(auto p : mp) {
        if(p.first[2] == 'A') {
            multiples[p.first] = getPathLength(dir, mp, p.first);
        }
    }
    ll res = -1;
    for(auto p : multiples) {
        if(res == -1) {
            res = p.second;
        }
        else {
            res = lcm(res, p.second);
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string dir, s;
    map<string, pair<string, string>> mp;
    getline(cin, dir);
    getline(cin, s);
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, " = ");
        vector<string> b = tokenize(a[1].substr(1, 8), ", ");
        mp[a[0]] = {b[0], b[1]};
    }
    part1(dir, mp);
    part2(dir, mp);
    return 0;
}
