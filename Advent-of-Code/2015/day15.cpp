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

void part1() {
    string s;
    vector<vector<ll>> v;
    while(getline(cin, s)) {
        vector<ll> cur;
        s = s.substr(s.find("capacity") + 9);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("durability") + 11);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("flavor") + 7);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("texture") + 8);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("calories") + 9);
        cur.push_back(stol(s.substr(0, s.find(","))));
        v.push_back(cur);
    }
    /*for(auto v2 : v) {
        for(auto x : v2) cout << x << ' ';
        cout << endl;
    }*/
    ll res = 0;
    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            for(int k=0;k<=100;k++) {
                for(int l=0;l<=100;l++) {
                    if(i + j + k + l == 100) {
                        ll prod = 1; 
                        for(int m=0;m<4;m++) {
                            ll cur = i * v[0][m] + j * v[1][m] + k * v[2][m] + l * v[3][m];
                            if(cur < 0) {
                                prod = 0;
                                break;
                            }
                            else {
                                prod *= cur;
                            }
                        }
                        /*if(prod > res) {
                            //cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
                            cout << prod <<  endl;
                        }*/
                        res = max(res, prod);
                    }
                }
            }
        }
    }
    cout << res << endl;
}  

void part2() {
    string s;
    vector<vector<ll>> v;
    while(getline(cin, s)) {
        vector<ll> cur;
        s = s.substr(s.find("capacity") + 9);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("durability") + 11);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("flavor") + 7);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("texture") + 8);
        cur.push_back(stol(s.substr(0, s.find(","))));
        s = s.substr(s.find("calories") + 9);
        cur.push_back(stol(s.substr(0, s.find(","))));
        v.push_back(cur);
    }
    /*for(auto v2 : v) {
        for(auto x : v2) cout << x << ' ';
        cout << endl;
    }*/
    ll res = 0;
    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            for(int k=0;k<=100;k++) {
                for(int l=0;l<=100;l++) {
                    if(i + j + k + l == 100) {
                        ll prod = 1; 
                        for(int m=0;m<4;m++) {
                            ll cal = i * v[0][4] + j * v[1][4] + k * v[2][4] + l * v[3][4];
                            if(cal != 500) continue;
                            ll cur = i * v[0][m] + j * v[1][m] + k * v[2][m] + l * v[3][m];
                            if(cur < 0) {
                                prod = 0;
                                break;
                            }
                            else {
                                prod *= cur;
                            }
                        }
                        /*if(prod > res) {
                            //cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
                            cout << prod <<  endl;
                        }*/
                        res = max(res, prod);
                    }
                }
            }
        }
    }
    cout << res << endl;
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
