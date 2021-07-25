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

int res = 0;
vector<pair<string, string>> v;
vector<int> cnt(1e5);
set<int> vis;

void handle(int idx) {
    cnt[idx]++;
    if(cnt[idx] == 2) {
        return;
    }
    string a = v[idx].first, b = v[idx].second;
    bool add = true;
    if(b[0] == '-') add = false;
    b = b.substr(1);
    int val = stoi(b);
    if(a == "nop") {
        handle(idx + 1);
    }
    if(a == "acc") {
        if(add) res += val;
        else res -= val;
        handle(idx + 1);
    }
    else if(a == "jmp") {
        if(add) handle(idx + val);
        else handle(idx - val);
        //cout << add << ' ' << val << endl;
    }
}

void part1() {
    string s;
    while(getline(cin, s)) {
        string a = s.substr(0, s.find(" "));
        string b = s.substr(s.find(" ") + 1);
        //cout << a << ' ' << b << endl;
        v.push_back({a, b});
    }
    //cnt[0]++;
    handle(0);
    //for(int i=0;i<10;i++) cout << cnt[i] << ' ';
    //cout << endl;
    cout << res << endl;
    return;
} 

bool handle2(int idx) {
    while(true) {
        if(idx >= v.size()) {
            return true;
        }
        if(vis.count(idx)) {
            return false;
        }
        vis.insert(idx);
        string a = v[idx].first, b = v[idx].second;
        bool add = true;
        if(b[0] == '-') add = false;
        int val = stoi(b.substr(1));
        if(a == "nop") {
            idx++;
        } 
        else if(a == "acc") {
            idx++;
            if(add) res += val;
            else res -= val;
        }
        else {
            if(add) idx += val;
            else idx -= val;
        }
    }
    return false;
}

void part2() {
    string s;
    while(getline(cin, s)) {
        string a = s.substr(0, s.find(" "));
        string b = s.substr(s.find(" ") + 1);
        //cout << a << ' ' << b << endl;
        v.push_back({a, b});
    }
    int n = v.size();
    for(int i=0;i<n;i++) {
        vis.clear();
        res = 0;
        if(v[i].first == "nop") {
            v[i].first = "jmp";
            if(handle2(0)) {
                cout << res << endl;
                return;
            }
            v[i].first = "nop";
        }
        else if(v[i].first == "jmp") {
            v[i].first = "nop";
            if(handle2(0)) {
                cout << res << endl;
                return;
            }
            v[i].first = "jmp";
        }
    }
    //cout << res << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
