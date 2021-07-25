//全力以赴
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
 
ll gcd(ll a, ll b) { 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}

ll extGcd(ll a, ll b, ll &x, ll &y) { // solves for x and y where ax+by=gcd(a,b)
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll modInv(ll a, ll p) { // solve for x=a^-1 where ax + py = 1 % p
    if(gcd(a, p) != 1) return -1; // modInv only exists if a and p are coprime (gcd(a, p) = 1)
    ll x, y;
    extGcd(a, p, x, y);
    x = (x % p + p) % p;
    return x;
}
   
ll lcm(ll a, ll b) {  
    return (a * b) / gcd(a,b);  
} 
 
/*
a^b: 
if b is even -> a^b = a^(b/2) * a^(b/2)
if b is odd -> a^b  = a * a^(b-1/2) * a^(b-1/2)
*/
ll modPow(ll a, ll n, ll mod) {
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

string calc(string s) {
    int n = s.length();
    string res;
    for(int i=0;i<n;i++) {
        int cnt = 1;
        while(i + 1 < n && s[i] == s[i+1]) {
            i++;
            cnt++;
        }
        res += (cnt + '0');
        res += s[i-cnt+1];
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    for(int i=0;i<40;i++) { // part1: 40, part2: 50
        s = calc(s);
    }
    cout << s.length() << endl;
}   

int main()  
{
    IOS
    /*int t;
    cin >> t;
    while(t--) solve();*/
    solve();
    return 0; 
}
