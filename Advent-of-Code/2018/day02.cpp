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
    string s;
    int cnt2 = 0, cnt3 = 0;
    while(getline(cin, s)) {
        vector<int> cnt(26);
        for(auto c : s) cnt[c-'a']++;
        bool has2 = false, has3 = false;
        for(int i=0;i<26;i++) {
            if(cnt[i] == 2) {
                has2 = true;
            }
            else if(cnt[i] == 3) {
                has3 = true;
            }
        }
        if(has2) cnt2++;
        if(has3) cnt3++;
    }
    cout << cnt2 * cnt3 << endl;
}

void part2() {
    string s;
    vector<string> v;
    while(getline(cin, s)) {
        v.push_back(s);
    }
    int n = v.size(), m = v[0].size();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int diff = 0;
            for(int k=0;k<m;k++) {
                if(v[i][k] != v[j][k]) diff++;
            }
            if(diff == 1) {
                cout << v[i] << endl;
                cout << v[j] << endl;
                return;
            }
        }
    }
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
