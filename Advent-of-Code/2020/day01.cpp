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
    vector<ll> a;
    ll x;
    while(cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) {
        int lo = 0, hi = n;
        ll target = 2020 - a[i];
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2; 
            if(a[mid] == target) {
                cout << target * a[i] << endl;
                return;
            }
            else if(a[mid] > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
    }
    cout << -1 << endl;
    return;
} 

void part2() {
    vector<ll> a;
    ll x;
    while(cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    sort(a.begin(), a.end());
    for(int i=0;i<n-2;i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            ll cur = a[i] + a[l] + a[r];
            if(cur == 2020) {
                cout << a[i] * a[l] * a[r] << endl;
                return;
            }
            else if(cur < 2020) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
