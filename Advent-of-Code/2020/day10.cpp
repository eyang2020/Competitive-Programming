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
    vector<int> v = {0};
    while(getline(cin, s)) {
        v.push_back(stoi(s));
    }
    sort(v.begin(), v.end());
    vector<int> cnt = {0, 0, 1};
    for(int i=1;i<v.size();i++) {
        cnt[v[i] - v[i-1] - 1]++;
    }
    cout << cnt[0] * cnt[2] << endl;
    return;
} 

ll fact(ll n) {
    ll res = 1;
    for(ll i=1;i<=n;i++) {
        res *= i;
    }
    return res;
}   

void part2() {
    string s;
    vector<ll> v = {0};
    while(getline(cin, s)) {
        v.push_back(stol(s));
    }
    int n = v.size();
    sort(v.begin(), v.end());
    vector<ll> dp(n);
    dp[n-1] = 1;
    for(int k=n-2;k>=0;k--) {
        for(int i=k+1;i<n&&abs(v[i]-v[k])<=3;i++) {
            dp[k] += dp[i]; 
        }
    }
    cout << dp[0] << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
