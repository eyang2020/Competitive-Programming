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

vector<vector<char>> pad1 = {
    {'1', '2', '3'},
    {'4', '5', '6'}, 
    {'7', '8', '9'}
};

vector<vector<char>> pad2 = {
    {'0', '0', '1', '0', '0'},
    {'0', '2', '3', '4', '0'},
    {'5', '6', '7', '8', '9'},
    {'0', 'A', 'B', 'C', '0'},
    {'0', '0', 'D', '0', '0'}
};

void part1() {
    int y = 1, x = 1;
    string s;
    string res;
    while(getline(cin, s)) {
        for(auto c : s) {
            if(c == 'U') y = max(0, y - 1);
            else if(c == 'D') y = min(2, y + 1);
            else if(c == 'L') x = max(0, x - 1);
            else x = min(2, x + 1);
        }
        res += pad1[y][x];
    }
    cout << res << endl;
}

void part2() {
    int y = 2, x = 0;
    string s;
    string res;
    while(getline(cin, s)) {
        for(auto c : s) {
            if(c == 'U') {
                if(y - 1 >= 0 && pad2[y-1][x] != '0') y--;
            }
            else if(c == 'D') {
                if(y + 1 < 5 && pad2[y+1][x] != '0') y++;
            }
            else if(c == 'L') {
                if(x - 1 >= 0 && pad2[y][x-1] != '0') x--;
            }
            else if(c == 'R') {
                if(x + 1 < 5 && pad2[y][x+1] != '0') x++;
            }
        }
        res += pad2[y][x];
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
