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

void part1(vector<vector<ll>> a) {
    ll res = 0;
    for(vector<ll> b : a) {
        bool done = false;
        vector<vector<ll>> diffs;
        diffs.push_back(b);
        while(!done) {
            done = true;
            vector<ll> cur = diffs.back();
            int n = cur.size();
            vector<ll> diff;
            for(int i=1;i<n;i++) {
                int val = cur[i] - cur[i-1];
                diff.push_back(val);
                if(val != 0) {
                    done = false;
                }
            }
            diffs.push_back(diff);
        }
        int n = diffs.size();
        for(int i=n-1;i>0;i--) {
            ll cur = diffs[i].back();
            ll next = cur + diffs[i-1].back();
            diffs[i-1].push_back(next);
        }
        res += diffs[0].back();
    }
    cout << res << endl;
}

void part2(vector<vector<ll>> a) {
    ll res = 0;
    for(vector<ll> b : a) {
        bool done = false;
        deque<ll> b2;
        for(ll x : b) {
            b2.push_back(x);
        }
        vector<deque<ll>> diffs;
        diffs.push_back(b2);
        while(!done) {
            done = true;
            deque<ll> cur = diffs.back();
            int n = cur.size();
            deque<ll> diff;
            for(int i=1;i<n;i++) {
                int val = cur[i] - cur[i-1];
                diff.push_back(val);
                if(val != 0) {
                    done = false;
                }
            }
            diffs.push_back(diff);
        }
        int n = diffs.size();
        for(int i=n-1;i>0;i--) {
            ll cur = diffs[i].front();
            ll next = diffs[i-1].front() - cur;
            diffs[i-1].push_front(next);
        }
        res += diffs[0].front();
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<vector<ll>> a;
    while(getline(cin, s)) {
        vector<string> b = tokenize(s, " ");
        vector<ll> c;
        for(auto d : b) {
            c.push_back(stol(d));
        }
        a.push_back(c);
    }
    part1(a);
    part2(a);
    return 0;
}
