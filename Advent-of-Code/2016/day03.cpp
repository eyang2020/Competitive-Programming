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
    string s;
    int cnt = 0;
    while(getline(cin, s)) {
        vector<int> v;
        string num;
        for(auto c : s) {
            if(c != ' ') num += c;
            else {
                if(num.length() > 0) v.push_back(stoi(num));
                num = "";
            } 
        }
        if(num.length() > 0) v.push_back(stoi(num));
        if(v[0] + v[1] > v[2] && v[0] + v[2] > v[1]&& v[1] + v[2] > v[0]) cnt++;
    }
    cout << cnt << endl;
}

void part2() {
    string s;
    vector<vector<int>> v;
    int cnt = 0;
    while(getline(cin, s)) {
        vector<int> v2;
        string num;
        for(auto c : s) {
            if(c != ' ') num += c;
            else {
                if(num.length() > 0) v2.push_back(stoi(num));
                num = "";
            } 
        }
        if(num.length() > 0) v2.push_back(stoi(num));
        v.push_back(v2);
    }
    int n = v.size();
    for(int i=0;i<n;i+=3) {
        for(int j=0;j<3;j++) {
            if(v[i][j] + v[i+1][j] > v[i+2][j] && v[i][j] + v[i+2][j] > v[i+1][j] && v[i+1][j] + v[i+2][j] > v[i][j]) cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
