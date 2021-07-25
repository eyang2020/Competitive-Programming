#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 2e5 + 5;
const ll MOD = 1e9+7;

int parent[N];
const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

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

void part1() {
    for(int i=0;i<N;i++) parent[i] = i;
    string s;
    while(getline(cin, s)) {
        int par = stoi(s.substr(0, s.find("<")));
        s = s.substr(s.find("<") + 4);
        string cur;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s[i] == ',' || s[i] == ' ') {
                if(cur.length() > 0) {
                    int x = stoi(cur);
                    cur = "";
                    Union(par, x);
                }
            }
            else {
                cur += s[i];
            }
        }
        if(cur.length() > 0) Union(par, stoi(cur));
    }
    int p = find(0), res = 1;
    for(int i=1;i<N;i++) if(find(i) == p) res++;
    cout << res << endl;
}

void part2() {
    for(int i=0;i<N;i++) parent[i] = i;
    string s;
    int mx = 0;
    while(getline(cin, s)) {
        int par = stoi(s.substr(0, s.find("<")));
        s = s.substr(s.find("<") + 4);
        string cur;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s[i] == ',' || s[i] == ' ') {
                if(cur.length() > 0) {
                    int x = stoi(cur);
                    cur = "";
                    mx = max(mx, x);
                    Union(par, x);
                }
            }
            else {
                cur += s[i];
            }
        }
        if(cur.length() > 0) {
            Union(par, stoi(cur));
            mx = max(mx, stoi(cur));
        }
    }
    int res = 0;
    for(int i=0;i<=mx;i++) {
        if(find(i) == i) res++;
    }
    cout << res << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
