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

map<ll, ll> blink(map<ll, ll> mp) {
    map<ll, ll> next;
    for(auto p : mp) {
        ll stone = p.first, cnt = p.second;
        string stoneStr = to_string(stone);
        if(cnt == 0) {
            continue;
        }
        else if(stone == 0) {
            next[1] += cnt;
        }
        else if(stoneStr.size() % 2 == 0) {
            int m = stoneStr.size() / 2;
            string lStr = stoneStr.substr(0, m), rStr = stoneStr.substr(m);
            ll l = stol(lStr), r = stol(rStr);
            next[l] += cnt;
            next[r] += cnt;
        }
        else {
            ll nextStone = stone * 2024;
            next[nextStone] += cnt;
        }
    }
    return next;
}

void part1(vector<ll> v) {
    map<ll, ll> mp;
    for(auto x : v) {
        mp[x]++;
    }
    for(int i=0;i<25;i++) {
        mp = blink(mp);
    }
    ll res = 0;
    for(auto p : mp) {
        res += p.second;
    }
    cout << res << endl;
}

void part2(vector<ll> v) {
    map<ll, ll> mp;
    for(auto x : v) {
        mp[x]++;
    }
    for(int i=0;i<75;i++) {
        mp = blink(mp);
    }
    ll res = 0;
    for(auto p : mp) {
        res += p.second;
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    getline(cin, s);
    vector<string> a = tokenize(s, " ");
    vector<ll> b;
    for(string x : a) {
        b.push_back(stol(x));
    }
    part1(b);
    part2(b);
    return 0;
}
