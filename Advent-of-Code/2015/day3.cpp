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
    int x = 0, y = 0;
    string s;
    cin >> s;
    int n = s.length();
    set<pair<int, int>> vis;
    int res = 1;
    vis.insert({0, 0});
    for(int i=0;i<n;i++) {
        char c = s[i];
        if(c == '^') {
            y++;
        }
        else if(c == 'v') {
            y--;
        }
        else if(c == '<') {
            x--;
        }
        else {
            x++;
        }
        if(!vis.count({x, y})) {
            vis.insert({x, y});
            res++;
        }
    }
    cout << res << endl;
    return;
} 

void part2() {
    string s;
    cin >> s;
    int k = 0; // k=0 -> santa, k=1 -> robot
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0; // santa:(x1, y1) robot:(x2,y2)
    set<pair<int, int>> st;
    st.insert({0, 0});
    for(auto c : s) {
        int dx = 0, dy = 0;
        if(c == '^') dy = 1;
        else if(c == 'v') dy = -1;
        else if(c == '<') dx = -1;
        else dx = 1;
        if(k == 0) {
            x1 += dx;
            y1 += dy;
            st.insert({x1, y1});
        }
        else {
            x2 += dx;
            y2 += dy;
            st.insert({x2, y2});
        }
        k = 1 - k;
    }
    cout << st.size() << endl;
    return;
}

int main()
{
    IOS
    part1();
    part2();
    return 0; 
}
