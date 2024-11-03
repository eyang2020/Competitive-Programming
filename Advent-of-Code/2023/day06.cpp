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

void part1(vector<ll> times, vector<ll> distances) {
    ll res = 0;
    int n = times.size();
    vector<ll> cnt(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<=times[i];j++) {
            ll dist = j * (times[i] - j);
            if(dist > distances[i]) {
                cnt[i]++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(res == 0) {
            res = cnt[i];
        }
        else {
            res *= cnt[i];
        }
    }
    cout << res << endl;
}

void part2(vector<ll> times, vector<ll> distances) {
    // Part 1 code was reused for Part 2
}

int main() {
    IOS
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<string> c = tokenize(a, " ");
    vector<string> d = tokenize(b, " ");
    vector<ll> times, distances;
    for(string s : c) {
        if(s.length() > 0 && isdigit(s[0])) {
            times.push_back(stol(s));
        }
    }
    for(string s : d) {
        if(s.length() > 0 && isdigit(s[0])) {
            distances.push_back(stol(s));
        }
    }
    part1(times, distances);
    part2(times, distances);
    return 0;
}
