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

bool isInvalidId(string s) {
    int n = s.length();
    return (n % 2 == 0) && (s.substr(0, n / 2) == s.substr(n / 2));
}

bool isInvalidId(ll x) {
    string s = to_string(x);
    return isInvalidId(s);
}

bool isInvalidIdV2(string s) {
    int n = s.length();
    for(int i=0;i<n-1;i++) {
        int m = i + 1;
        string prefix = s.substr(0, m);
        if(n % m != 0) {
            continue;
        }
        int k = n / m;
        string expected = "";
        for(int j=0;j<k;j++) {
            expected += prefix;
        }
        if(expected == s) {
            return true;
        }
    }
    return false;
}

bool isInvalidIdV2(ll x) {
    string s = to_string(x);
    return isInvalidIdV2(s);
}

void part1(vector<pair<ll, ll>> ranges) {
    ll res = 0;
    for (auto p : ranges) {
        for (ll i = p.first; i <= p.second; i++) {
            if (isInvalidId(i)) {
                res += i;
            }
        }
    }
    cout << res << '\n';
}

void part2(vector<pair<ll, ll>> ranges) {
    ll res = 0;
    for (auto p : ranges) {
        for (ll i = p.first; i <= p.second; i++) {
            if(isInvalidIdV2(i)) {
                res += i;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    IOS
    string s;
    vector<pair<ll, ll>> ranges;
    while(getline(cin, s)) {
        vector<string> v = tokenize(s, ",");
        for(string s2 : v) {
            vector<string> v2 = tokenize(s2, "-");
            pair<ll, ll> range = {stol(v2[0]), stol(v2[1])};
            ranges.push_back(range);
        }
    }
    part1(ranges);
    part2(ranges);
    return 0;
}
