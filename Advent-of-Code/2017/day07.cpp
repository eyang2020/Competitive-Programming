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
const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

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
    map<string, int> w;
    map<string, vector<string>> adj;
    map<string, bool> vis;
    while(getline(cin, s)) {
        string p = s.substr(0, s.find("(") - 1);
        s = s.substr(s.find("(") + 1);
        int val = stoi(s.substr(0, s.find(")")));
        if(s.find("->") != string::npos) {
            s = s.substr(s.find("->") + 3);
            while(s.find(",") != string::npos) {
                adj[p].push_back(s.substr(0, s.find(",")));
                s = s.substr(s.find(",") + 2);
            }
            if(s.length() > 0) {
                adj[p].push_back(s);
            }
        }
        w[p] = val;
    }
    for(auto p : adj) {
        auto v = p.second;
        for(auto x : v) vis[x] = true;
    }
    for(auto p : adj) {
        string par = p.first;
        if(!vis[par]) cout << par << endl;
    }
}

void part2() {
    string s;
    map<string, int> w;
    map<string, vector<string>> adj;
    map<string, bool> vis;
    while(getline(cin, s)) {
        string p = s.substr(0, s.find("(") - 1);
        s = s.substr(s.find("(") + 1);
        int val = stoi(s.substr(0, s.find(")")));
        if(s.find("->") != string::npos) {
            s = s.substr(s.find("->") + 3);
            while(s.find(",") != string::npos) {
                adj[p].push_back(s.substr(0, s.find(",")));
                s = s.substr(s.find(",") + 2);
            }
            if(s.length() > 0) {
                adj[p].push_back(s);
            }
        }
        w[p] = val;
    }
    for(auto p : adj) {
        auto v = p.second;
        for(auto x : v) vis[x] = true;
    }
    map<string, int> sum;
    for(auto p : adj) {
        string par = p.first;
        auto v = p.second;
        for(auto x : v) {
            sum[par] += w[x];
            sum[x] = w[x];
        }
    }
    int res = 0;
    for(auto p : adj) {
        string par = p.first;
        auto v = p.second;
        int last = -1;
        for(auto x : v) {
            int curSum = sum[x];
            if(last == -1) last = curSum;
            else {
                if(last != curSum) {
                    cout << par << endl;
                    cout << curSum << endl;
                    cout << last << endl;
                    res = abs(curSum - last);
                    break;
                }
            }
        }
    }
    cout << res << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
