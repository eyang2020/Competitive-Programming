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

int n;

bool ok(string s) {
    for(int i=0;i<n;i++) if(s[i] == 'i' || s[i] == 'o' || s[i] == 'l') return false;
    bool ok1 = false, ok2 = false;
    for(int i=0;i+2<n;i++) {
        if(s[i] + 1 == s[i+1] && s[i+1] + 1 == s[i+2]) {
            ok1 = true;
            break;
        }
    }
    int last = -1;
    for(int i=1;i<n;i++) {
        if(s[i] == s[i-1]) {
            if(last == -1) {
                last = i;
                i++;
            }
            else {
                if(s[last] != s[i]) {
                    ok2 = true;
                    break;
                }
            }
        }
    }
    return ok1 && ok2;
}

void part1() {
    string s;
    cin >> s;
    n = s.length();
    string x(n, 'z');
    while(s != x) {
        for(int pos=n-1;pos>=0;pos--) {
            if(s[pos] != 'z') {
                s[pos]++;
                break;
            }
            else {
                s[pos] = 'a';
            }
        }
        if(ok(s)) {
            cout << s << endl;
            return;
        }
    }
}

void part2() {
    // part 2 was to use output from part 1 as new input.
}

int main()
{
    IOS
    part1();
    //part2();
    return 0;
}
