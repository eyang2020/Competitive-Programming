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
    int n = 1000, m = 1000;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    string s;
    vector<vector<int>> v;
    while(getline(cin, s)) {
        string idx = s.substr(1, s.find(" "));
        s = s.substr(s.find("@") + 2);
        string x = s.substr(0, s.find(","));
        s = s.substr(s.find(",") + 1);
        string y = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        string w = s.substr(0, s.find("x"));
        s = s.substr(s.find("x") + 1);
        string h = s;
        vector<int> cur = {stoi(idx), stoi(x), stoi(y), stoi(w), stoi(h)};
        v.push_back(cur);
    }
    for(auto cur : v) {
        int x = cur[1], y = cur[2], w = cur[3], h = cur[4];
        for(int i=1;i<=h;i++) {
            for(int j=1;j<=w;j++) {
                grid[y+i][x+j]++;
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(grid[i][j] >= 2) res++;
        }
    }
    cout << res << endl;
}

void part2() {
    int n = 1000, m = 1000;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    string s;
    vector<vector<int>> v;
    while(getline(cin, s)) {
        string idx = s.substr(1, s.find(" "));
        s = s.substr(s.find("@") + 2);
        string x = s.substr(0, s.find(","));
        s = s.substr(s.find(",") + 1);
        string y = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        string w = s.substr(0, s.find("x"));
        s = s.substr(s.find("x") + 1);
        string h = s;
        vector<int> cur = {stoi(idx), stoi(x), stoi(y), stoi(w), stoi(h)};
        v.push_back(cur);
    }
    for(auto cur : v) {
        int curID = cur[0], x = cur[1], y = cur[2], w = cur[3], h = cur[4];
        for(int i=1;i<=h;i++) {
            for(int j=1;j<=w;j++) {
                grid[y+i][x+j]++;
            }
        }
    }
    for(auto cur : v) {
        int curID = cur[0], x = cur[1], y = cur[2], w = cur[3], h = cur[4];
        bool ok = true;
        for(int i=1;i<=h;i++) {
            for(int j=1;j<=w;j++) {
                if(grid[y+i][x+j] > 1) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            cout << curID << endl;
            break;
        }
    }
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
