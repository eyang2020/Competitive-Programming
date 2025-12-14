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

void part1(vector<string> v) {
    int n = v.size(), res = 0;
    for(int i=0;i<n;i++) {
        int max1 = 0, max2 = 0;
        string s = v[i];
        int m = s.length();
        for(int j=0;j<m;j++) {
            int x = s[j] - '0';
            if(x > max1 && j != m - 1) {
                max1 = x;
                max2 = 0;
            } else {
                max2 = max(max2, x);
            }
        }
        int best = max1 * 10 + max2;
        res += best;
    }
    cout << res << '\n';
}

void part2(vector<string> v) {
    ll res = 0;
    for(string s : v) {
        string best = "";
        int n = s.length();
        for(int i=0;i<n;i++) {
            int m = best.length();
            bool used = false;
            for(int j=0;j<m;j++) {
                if(((s[i] - '0') > (best[j] - '0')) && ((n - i - 1) >= (12 - j - 1))) {
                    best = best.substr(0, j) + s[i];
                    used = true;
                    break;
                }
            }
            if(!used && m < 12) {
                best += s[i];
            }
        }
        res += stol(best);
    }
    cout << res << '\n';
}

int main() {
    IOS
    string s;
    vector<string> v;
    while(getline(cin, s)) {
        v.push_back(s);
    }    
    part1(v);
    part2(v);
    return 0;
}
