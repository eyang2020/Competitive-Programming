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
    int res = 0;
    for(int i=240298;i<=784956;i++) {
        string s = to_string(i);
        bool ok1 = false, ok2 = true;
        for(int i=1;i<6;i++) {
            if(s[i] == s[i-1]) {
                ok1 = true;
            }
            if(s[i] < s[i-1]) {
                ok2 = false;
                break;
            }
        }
        if(ok1 && ok2) res++;
    }
    cout << res << endl;
    return;
} 

void part2() {
    int res = 0;
    for(int i=240298;i<=784956;i++) {
        string s = to_string(i);
        bool ok1 = false, ok2 = true;
        for(int i=1;i<6;i++) {
            if(s[i] == s[i-1] && !ok1) {
                ok1 = true;
                if(i-2 >= 0 && s[i-2] == s[i]) {
                    ok1 = false;
                }
                if(i + 1 < 6 && s[i+1] == s[i]) {
                    ok1 = false;
                }
            }
            if(s[i] < s[i-1]) {
                ok2 = false;
                break;
            }
        }
        if(ok1 && ok2) res++;
    }
    cout << res << endl;
    return;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
