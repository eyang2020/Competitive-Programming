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
    int n = 25;
    vector<ll> v;
    string s;
    while(getline(cin, s)) {
        v.push_back(stol(s));
    }
    int start = 0;
    int m = v.size();
    for(int i=n;i<m;i++) {
        bool ok = false;
        for(int j=start;j<i;j++) {
            for(int k=j+1;k<i;k++) {
                if(v[j] + v[k] == v[i]) {
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) {
            cout << v[i] << endl;
            return;
        }
        start++;
    }
    //20874512 was my res for part 1
    return;
} 

void part2() {
    vector<ll> v;
    string s;
    while(getline(cin, s)) {
        v.push_back(stol(s));
    }
    ll target = 20874512;
    int m = v.size();
    /*for(int i=0;i<m;i++) {
        ll curSum = v[i];
        for(int j=i+1;j<=m;j++) {
            if(curSum == target) {
                cout << i << ' ' << j-1 << endl; // subarray from i to j-1 contains target sum
                return;
            }
            if(curSum > target || j == m) {
                break;
            }
            curSum += v[j];
        }
    }*/
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for(int i=424;i<=440;i++) {
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }
    cout << mn + mx << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
