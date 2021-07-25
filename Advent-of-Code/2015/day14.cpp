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

void solve() {
    string s;
    map<string, vector<int>> mp; // v: velocity, flyTime, restTime, curFlyTime, curRestTime, dist
    map<string, bool> fly;
    while(getline(cin, s)) {
        string name = s.substr(0, s.find(" "));
        vector<int> temp;
        s = s.substr(s.find("fly") + 4);
        temp.push_back(stoi(s.substr(0, s.find(" "))));
        s = s.substr(s.find("for") + 4);
        temp.push_back(stoi(s.substr(0, s.find(" "))));
        s = s.substr(s.find("for") + 4);
        temp.push_back(stoi(s.substr(0, s.find(" "))));
        temp.push_back(0);
        temp.push_back(0);
        temp.push_back(0);
        mp[name] = temp;
        fly[name] = true;
    }
    /*for(auto p : mp) {
        cout << p.first << ' ';
        for(auto x : p.second) cout << x << ' ';
        cout << endl;
    }*/
    for(int i=1;i<=1;i++) {
        for(auto p : mp) {
            string name = p.first;
            vector<int> v = p.second;
            int velocity = v[0], flyTime = v[1], restTime = v[2];
            int curFlyTime = v[3], curRestTime = v[4], dist = v[5];
            bool flight = fly[name];
            //cout << name << ' ' << curFlyTime << ' ' << flyTime << endl;
            if(flight) {
                if(curFlyTime < flyTime) {
                    curFlyTime++;
                    dist += velocity;
                }
                else {
                    curFlyTime = 0;
                    flight = false;
                }
            } 
            else {
                if(curRestTime < restTime) {
                    curRestTime++;
                }
                else {
                    curRestTime = 0;
                    flight = true;
                }
            }
            // update
            //cout << name << ' ' << curFlyTime << ' ' << flyTime << endl;
            v[3] = curFlyTime;
            v[4] = curRestTime;
            v[5] = dist;
            mp[name] = v;
            fly[name] = flight;
        }
    }
    int res = 0;
    for(auto p : mp) {
        auto v = p.second;
        //cout << v[5] << endl;
        res = max(res, v[5]);
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
