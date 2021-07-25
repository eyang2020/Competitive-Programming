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
    vector<string> a;
    string s;
    while(cin >> s) {
        a.push_back(s);
    }
    int res = 0;
    int curX = 0, curY = 0;
    int n = a.size(), m = a[0].length();
    
    vector<string> temp;
    for(auto x : a) temp.push_back(x);

    while(curY < n) {
        curX = (curX + 3) % m;
        curY++;
        if(a[curY][curX] == '#') {
            res++;
            temp[curY][curX] = 'X';
        }
        else temp[curY][curX] = 'O';
    }
    cout << res << endl;

    //for(auto x : temp) cout << x << endl;
    return;
}

int n, m;
vector<string> a;

ll calc(int dX, int dY) {
    int curX = 0, curY = 0;
    ll res = 0;
    while(curY < n) {
        curX = (curX + dX) % m;
        curY += dY;
        if(a[curY][curX] == '#') {
            res++;
        }
    }
    return res;
}

void part2() {
    string s;
    while(cin >> s) {
        a.push_back(s);
    }
    ll res = 1;
    n = a.size(), m = a[0].length();
    res = calc(1, 1) * calc(3, 1) * calc(5, 1) * calc(7, 1) * calc(1, 2);
    cout << res << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
