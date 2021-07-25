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
    string s;
    int res = 0;
    while(getline(cin, s)) {
        int lo = 0, hi = 127;
        for(int i=0;i<7;i++) {
            if(s[i] == 'F') {
                hi = lo + (hi - lo) / 2;
            }
            else {
                lo = ceil(lo + (hi - lo) / 2.0);
            }
            //cout << lo << ' ' << hi << endl;
        }
        int row = 0, col = 0;
        if(s[6] == 'F') row = lo;
        else row = hi;
        //cout << s[6] << endl;
        //cout << lo << ' ' << hi << ' ' << row << endl;

        lo = 0, hi = 7;
        for(int i=7;i<10;i++) {
            if(s[i] == 'L') {
                hi = lo + (hi - lo) / 2;
            }
            else {
                lo = ceil(lo + (hi - lo) / 2.0);
            }
        }
        if(s[9] == 'L') col = lo;
        else col = hi;
        //cout << row << ' ' << col << endl;
        int curRes = row * 8 + col;
        res = max(res, curRes);
    }
    cout << res << endl;
    return;
} 

void part2() {
    string s;
    int res = 0;
    vector<bool> vis(872);
    while(getline(cin, s)) {
        int lo = 0, hi = 127;
        for(int i=0;i<7;i++) {
            if(s[i] == 'F') {
                hi = lo + (hi - lo) / 2;
            }
            else {
                lo = ceil(lo + (hi - lo) / 2.0);
            }
            //cout << lo << ' ' << hi << endl;
        }
        int row = 0, col = 0;
        if(s[6] == 'F') row = lo;
        else row = hi;
        //cout << s[6] << endl;
        //cout << lo << ' ' << hi << ' ' << row << endl;

        lo = 0, hi = 7;
        for(int i=7;i<10;i++) {
            if(s[i] == 'L') {
                hi = lo + (hi - lo) / 2;
            }
            else {
                lo = ceil(lo + (hi - lo) / 2.0);
            }
        }
        if(s[9] == 'L') col = lo;
        else col = hi;
        int curRes = row * 8 + col;
        vis[curRes] = true;
    }
    // 871 seats total
    for(int i=1;i<871;i++) {
        if(!vis[i]) cout << i << endl;
    }
    // my seat is was 640, i manually checked using given conditions
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
