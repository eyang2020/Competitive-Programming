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

void part1(vector<pair<char, int>> v) {
    int res = 0, cur = 50;
    for(auto p : v) {
        char c = p.first;
        int x = p.second;
        int diff = x % 100;
        if(c == 'L') {
            cur = (cur - diff + 100) % 100;
        } else {
            cur = (cur + diff) % 100;
        }
        if(cur == 0) {
            res++;
        }
    }
    cout << res << '\n';
}

void part2(vector<pair<char, int>> v) {
    int res = 0, cur = 50;
    for(auto p : v) {
        char c = p.first;
        int x = p.second;
        int diff = x % 100;
        res += x / 100;
        if(c == 'L') {
            if(cur - diff <= 0 && cur != 0) {
                res++;
            }
            cur = (cur - diff + 100) % 100;
        } else {
            if(cur + diff >= 100) {
                res++;
            }
            cur = (cur + diff) % 100;
        }
    }
    cout << res << '\n';
}

int main() {
    IOS
    string s;
    vector<pair<char, int>> v;
    while(getline(cin, s)) {
        v.push_back({s[0], stoi(s.substr(1))});
    }
    part1(v);
    part2(v);
    return 0;
}
