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
    map<string, int> mp;
    vector<vector<string>> v;
    while(getline(cin, s)) {
        string r = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string op = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string x = s.substr(0, s.find(" "));
        s = s.substr(s.find("if") + 3);
        string r2 = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string op2 = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string x2 = s;
        vector<string> temp = {r, op, x, r2, op2, x2};
        v.push_back(temp);
    }
    for(auto cur : v) {
        string r = cur[0];
        string op = cur[1];
        int x = stoi(cur[2]);
        string r2 = cur[3];
        string op2 = cur[4];
        int x2 = stoi(cur[5]);
        if(op2 == "==") {
            if(mp[r2] != x2) continue;
        }
        else if(op2 == "!=") {
            if(mp[r2] == x2) continue;
        }
        else if(op2 == ">") {
            if(mp[r2] <= x2) continue;
        }
        else if(op2 == "<") {
            if(mp[r2] >= x2) continue;
        }
        else if(op2 == ">=") {
            if(mp[r2] < x2) continue;
        }
        else if(op2 == "<=") {
            if(mp[r2] > x2) continue;
        }
        if(op == "inc") {
            mp[r] += x;
        }
        else {
            mp[r] -= x;
        }
    }
    int mx = INT_MIN;
    for(auto p : mp) {
        mx = max(mx, p.second);
    }
    cout << mx << endl;
}

void part2() {
    string s;
    map<string, int> mp;
    vector<vector<string>> v;
    int mx = INT_MIN;
    while(getline(cin, s)) {
        string r = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string op = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string x = s.substr(0, s.find(" "));
        s = s.substr(s.find("if") + 3);
        string r2 = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string op2 = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        string x2 = s;
        vector<string> temp = {r, op, x, r2, op2, x2};
        v.push_back(temp);
    }
    for(auto cur : v) {
        string r = cur[0];
        string op = cur[1];
        int x = stoi(cur[2]);
        string r2 = cur[3];
        string op2 = cur[4];
        int x2 = stoi(cur[5]);
        if(op2 == "==") {
            if(mp[r2] != x2) continue;
        }
        else if(op2 == "!=") {
            if(mp[r2] == x2) continue;
        }
        else if(op2 == ">") {
            if(mp[r2] <= x2) continue;
        }
        else if(op2 == "<") {
            if(mp[r2] >= x2) continue;
        }
        else if(op2 == ">=") {
            if(mp[r2] < x2) continue;
        }
        else if(op2 == "<=") {
            if(mp[r2] > x2) continue;
        }
        if(op == "inc") {
            mp[r] += x;
        }
        else {
            mp[r] -= x;
        }
        mx = max(mx, mp[r]);
    }
    for(auto p : mp) {
        mx = max(mx, p.second);
    }
    cout << mx << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
