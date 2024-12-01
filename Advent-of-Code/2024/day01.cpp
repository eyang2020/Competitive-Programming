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

void part1(vector<ll> left, vector<ll> right) {
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int n = left.size();
    ll res = 0;
    for(int i=0;i<n;i++) {
        res += abs(left[i] - right[i]);
    }
    cout << res << endl;
}

void part2(vector<ll> left, vector<ll> right) {
    int n = left.size();
    ll res = 0;
    map<ll, ll> mp;
    for(int i=0;i<right.size();i++) {
        mp[right[i]]++;
    }
    for(int i=0;i<left.size();i++) {
        res += left[i] * mp[left[i]];
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<ll> left, right;
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, "   ");
        left.push_back(stol(a[0]));
        right.push_back(stol(a[1]));
    }
    part1(left, right);
    part2(left, right);
    return 0;
}
