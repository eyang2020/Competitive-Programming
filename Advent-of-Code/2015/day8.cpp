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
    int len = 0;
    int charCnt = 0;
    while(getline(cin, s)) {
        int n = s.length();
        len += n;
        for(int i=1;i<n-1;i++) {
            if(s[i] == '\\' && s[i+1]== '\\') {
                i++;
                charCnt++;
            }
            else if(s[i] == '\\' && s[i+1] == 'x' && i + 3 < n - 1) {
                i += 3;
                charCnt++;
            }
            else if(s[i] != '\"'){
                charCnt++;
            }
        }
    }
    //cout << len << endl;
    //cout << charCnt << endl;
    cout << len - charCnt << endl;
}

void part2() {
    string s;
    int len = 0;
    int charCnt = 0;
    while(getline(cin, s)) {
        int n = s.length();
        len += n;
        int add = 0;
        for(int i=1;i<n-1;i++) {
            if(s[i] == '\\') {
                add++;
            }
            else if(s[i] == '\"') {
                add++;
            }
        }
        charCnt += n + add + 4;
        //cout << n + add + 4 << endl;
    }
    //cout << charCnt << endl;
    //cout << len << endl;
    cout << charCnt - len << endl;                               
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
