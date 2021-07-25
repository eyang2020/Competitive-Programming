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
    ll x;
    cin >> x;
    string s;
    cin >> s;
    string delim = ",";
    int pos = 0;
    vector<ll> v;
    while((pos = s.find(delim)) != string::npos) {
        string tok = s.substr(0, pos);
        if(tok != "x") {
            v.push_back(stol(tok));
        }
        s.erase(0, pos + delim.size());
    }
    if(s.size() > 0 && s[0] != 'x') {
        v.push_back(stol(s));
    }
    int n = v.size();
    ll wait = 0;
    ll id = 0;
    ll diff = INT_MAX;
    for(int i=0;i<n;i++) {
        ll cur = v[i];
        ll y = ceil(x / (double)cur) * cur;
        if(abs(y - x) < diff) {
            diff = abs(y - x);
            id = cur;
            wait = y;
        }
    }

    cout << (wait - x) * id << endl;
    return;
} 

ll inv(ll a, ll m) 
{ 
    ll m0 = m, t, q; 
    ll x0 = 0, x1 = 1; 
  
    if (m == 1) 
       return 0; 
  
    // Apply extended Euclid Algorithm 
    while (a > 1) 
    { 
        // q is quotient 
        q = a / m; 
  
        t = m; 
  
        // m is remainder now, process same as 
        // euclid's algo 
        m = a % m, a = t; 
  
        t = x0; 
  
        x0 = x1 - q * x0; 
  
        x1 = t; 
    } 
  
    // Make x1 positive 
    if (x1 < 0) 
       x1 += m0; 
  
    return x1; 
} 

// chinese remainder theorem
ll crt(vector<ll> num,vector<ll> rem, int k) 
{ 
    // Compute product of all numbers 
    ll prod = 1; 
    for (int i = 0; i < k; i++) 
        prod *= num[i]; 
  
    // Initialize result 
    ll result = 0; 
  
    // Apply above formula 
    for (int i = 0; i < k; i++) 
    { 
        ll pp = prod / num[i]; 
        result += rem[i] * inv(pp, num[i]) * pp; 
    } 
  
    return result % prod; 
} 

void part2() {
    string s;
    cin >> s;
    string delim = ",";
    int pos = 0;
    vector<ll> v;
    vector<ll> idx;
    int p = 0;
    while((pos = s.find(delim)) != string::npos) {
        string tok = s.substr(0, pos);
        if(tok != "x") {
            v.push_back(stol(tok));
            idx.push_back(p);
        }
        p++;
        s.erase(0, pos + delim.size());
    }
    if(s.size() > 0 && s[0] != 'x') {
        v.push_back(stol(s));
        idx.push_back(p);
    }
    int n = v.size();
    vector<ll> rem(n);
    for(int i=0;i<n;i++) {
        rem[i] = (-idx[i] + v[i]) % v[i]; // t + 1 % busID[1] = 0 -> t % busID[1] = (-1 + mod) % mod
    }
    /*for(int i=0;i<n;i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    for(int i=0;i<n;i++) {
        cout << rem[i] << ' ';
    }
    cout << endl;*/
    cout << crt(v, rem, n) << endl;
    return;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
