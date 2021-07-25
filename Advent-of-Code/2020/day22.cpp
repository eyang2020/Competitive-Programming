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
    getline(cin, s);
    queue<int> q1, q2;
    while(getline(cin, s)) {
        if(s.length() == 0) break;
        q1.push(stoi(s));
    }
    getline(cin, s);
    while(getline(cin, s)) {
        q2.push(stoi(s));
    }
    int n = q1.size() + q2.size();
    while(!q1.empty() && !q2.empty()) {
        int x1 = q1.front(), x2 = q2.front();
        q1.pop(), q2.pop();
        if(x1 > x2) {
            q1.push(x1);
            q1.push(x2);
        }
        else {
            q2.push(x2);
            q2.push(x1);
        }
    }
    int res = 0;
    if(q1.size() == 0) {
        while(!q2.empty()) {
            res += q2.front() * n;
            n--;
            q2.pop();
        }
    }
    else {
        while(!q1.empty()) {
            res += q1.front() * n;
            n--;
            q1.pop();
        }
    }
    cout << res << endl;
}

void part2() {
    
}

int main()
{
    IOS
    part1();
    //part2();
    return 0;
}
