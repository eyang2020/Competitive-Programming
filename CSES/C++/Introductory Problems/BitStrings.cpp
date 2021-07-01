#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

ll mpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    if(a == 0) return 0;
    while(b > 0) {
        if(b & 1) res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << mpow(2LL, n, MOD) << endl;
}
