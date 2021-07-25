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

void part1() {
    int x;
    cin >> x;
    for(int i=1;i<=x/10;i++) {
        int cnt = 0;
        for(int j=1;j<=sqrt(i);j++) {
            if(i % j == 0) {
                cnt += 10 * j;
                if(i / j != j) cnt += 10 * (i / j);
            }
        }
        if(cnt >= x) {
            cout << i << endl;
            return;
        }
    }
}

void part2() {
    int x;
    cin >> x;
    map<int, int> mp;
    for(int i=1;i<=x/11;i++) {
        int cnt = 0;
        for(int j=1;j<=sqrt(i);j++) {
            if(i % j == 0) {
                if(mp[j] < 50) {
                    cnt += 11 * j;
                    mp[j]++;
                }
                if(i / j != j) {
                    if(mp[i/j] < 50) {
                        cnt += 11 * (i / j);
                        mp[i/j]++;
                    }
                }
            }
        }
        if(cnt >= x) {
            cout << i << endl;
            return;
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
