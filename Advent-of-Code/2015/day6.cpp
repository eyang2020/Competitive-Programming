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
    vector<vector<int>> grid(1000, vector<int>(1000));
    string s;
    while(getline(cin, s)) {
        string word = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        if(word == "turn") {
            string op = s.substr(0, s.find(" "));
            s = s.substr(s.find(" ") + 1);
            int y1, x1, y2, x2;
            y1 = stoi(s.substr(0, s.find(",")));
            x1 = stoi(s.substr(s.find(",") + 1, s.find(" ")));
            s = s.substr(s.find("through") + 8);
            y2 = stoi(s.substr(0, s.find(",")));
            x2 = stoi(s.substr(s.find(",") + 1));
            //cout << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << endl;
            if(op == "on") {
                for(int i=y1;i<=y2;i++) {
                    for(int j=x1;j<=x2;j++) {
                        grid[i][j] = 1;
                    }
                }
            }
            else {
                for(int i=y1;i<=y2;i++) {
                    for(int j=x1;j<=x2;j++) {
                        grid[i][j] = 0;
                    }
                }
            }
        }
        else { // toggle x = 1 - x
            int y1, x1, y2, x2;
            y1 = stoi(s.substr(0, s.find(",")));
            x1 = stoi(s.substr(s.find(",") + 1, s.find(" ")));
            s = s.substr(s.find("through") + 8);
            y2 = stoi(s.substr(0, s.find(",")));
            x2 = stoi(s.substr(s.find(",") + 1));
            for(int i=y1;i<=y2;i++) {
                for(int j=x1;j<=x2;j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            if(grid[i][j]) res++;
        }
    }
    cout << res << endl;
}

void part2() {
    vector<vector<int>> grid(1000, vector<int>(1000));
    string s;
    while(getline(cin, s)) {
        string word = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        if(word == "turn") {
            string op = s.substr(0, s.find(" "));
            s = s.substr(s.find(" ") + 1);
            int y1, x1, y2, x2;
            y1 = stoi(s.substr(0, s.find(",")));
            x1 = stoi(s.substr(s.find(",") + 1, s.find(" ")));
            s = s.substr(s.find("through") + 8);
            y2 = stoi(s.substr(0, s.find(",")));
            x2 = stoi(s.substr(s.find(",") + 1));
            //cout << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << endl;
            if(op == "on") {
                for(int i=y1;i<=y2;i++) {
                    for(int j=x1;j<=x2;j++) {
                        grid[i][j]++;
                    }
                }
            }
            else {
                for(int i=y1;i<=y2;i++) {
                    for(int j=x1;j<=x2;j++) {
                        grid[i][j] = max(0, grid[i][j] - 1);
                    }
                }
            }
        }
        else {
            int y1, x1, y2, x2;
            y1 = stoi(s.substr(0, s.find(",")));
            x1 = stoi(s.substr(s.find(",") + 1, s.find(" ")));
            s = s.substr(s.find("through") + 8);
            y2 = stoi(s.substr(0, s.find(",")));
            x2 = stoi(s.substr(s.find(",") + 1));
            for(int i=y1;i<=y2;i++) {
                for(int j=x1;j<=x2;j++) {
                    grid[i][j] += 2;
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            res += grid[i][j];
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
