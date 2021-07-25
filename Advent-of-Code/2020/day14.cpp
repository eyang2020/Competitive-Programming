#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 3e5 + 5;
const ll MOD = 1e9+7;

int parent[N];

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int xPar = find(x), yPar = find(y);
    if(xPar != yPar) parent[xPar] = yPar;
}

ll nCr(ll n, ll r) {
    ll res = 1;
    for(ll i=1;i<=r;i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}

int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int v;
    cin >> v;
    return v;
}

int msbPos(int n) {
    if(n == 0) return 0;
    int msbPos = 0;
    n /= 2;
    while(n != 0) {
        n /= 2;
        msbPos++;
    }
    return msbPos;
}

void solve() {

}

void part1() {
    string s;
    map<ll, ll> mp;
    string mask = "";
    int n = 0;
    while(getline(cin, s)) {
        if(s.find("mask") != string::npos) {
            mask = s.substr(s.find("=") + 2);
            n = mask.length();
            //cout << mask << endl;
        }
        else {
            s = s.substr(s.find("[") + 1);
            ll idx = stol(s.substr(0, s.find("]")));
            ll val = stol(s.substr(s.find("=") + 2));
            //cout << idx << ' ' << val << endl;
            for(int i=n-1;i>=0;i--) {
                if(mask[i] == '1') {
                    //cout <<  "i:" << n-i-1 << endl;
                    val |= (1LL<<(n-i-1));
                }
                else if(mask[i] == '0') {
                    val &= ~(1LL<<(n-i-1));
                }
            }
            mp[idx] = val;
            //cout << idx << ' ' << val << endl;
        }
    }
    ll res = 0;
    for(auto p : mp) {
        //cout << p.first << ' ' << p.second << endl;
        res += p.second;
    }
    cout << res << endl;
}

void part2() {
    string s;
    map<ll, ll> mp;
    string mask = "";
    int n = 0;
    while(getline(cin, s)) {
        if(s.find("mask") != string::npos) {
            mask = s.substr(s.find("=") + 2);
            n = mask.length();
            //cout << mask << endl;
        }
        else {
            s = s.substr(s.find("[") + 1);
            ll idx = stol(s.substr(0, s.find("]")));
            ll val = stol(s.substr(s.find("=") + 2));
            //cout << idx << ' ' << val << endl;
            vector<ll> newIdx;
            for(int i=n-1;i>=0;i--) {
                if(mask[i] == '1') {
                    idx |= (1LL<<(n-i-1));
                }
                else if(mask[i] == 'X') {
                    newIdx.push_back(n-i-1);
                    idx &= ~(1LL<<(n-i-1)); // set to 0 initially
                }
            }
            int m = newIdx.size();
            int sz = (1<<m);
            for(int i=0;i<sz;i++) {
                ll tempIdx = idx;
                vector<ll> change;
                for(int j=0;j<m;j++) {
                    if(i & (1<<j)) {
                        change.push_back(newIdx[j]);
                    }
                }
                for(auto x : change) {
                    tempIdx |= (1LL<<(x));
                    mp[tempIdx] = val;
                }
                if(change.size() == 0) {
                    mp[tempIdx] = val;
                }
            }
        }
    }
    ll res = 0;
    for(auto p : mp) {
        //cout << p.first << ' ' << p.second << endl;
        res += p.second;
    }
    cout << res << endl;
}

int main()
{
    IOS
    //solve();
    //part1();
    part2();
    return 0;
}
