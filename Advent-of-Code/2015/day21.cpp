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

vector<vector<int>> weapons = {
    {8, 4, 0}, 
    {10, 5, 0}, 
    {25, 6, 0}, 
    {40, 7, 0}, 
    {74, 8, 0}
};
vector<vector<int>> armor = {
    {0, 0, 0},
    {13, 0, 1}, 
    {31, 0, 2}, 
    {53, 0, 3}, 
    {75, 0, 4}, 
    {102, 0, 5}
};
vector<vector<int>> rings = {
    {0, 0, 0},
    {0, 0, 0},
    {25, 1, 0}, 
    {50, 2, 0}, 
    {100, 3, 0}, 
    {20, 0, 1}, 
    {40, 0, 2},
    {80, 0, 3}
};

void part1() {
    int hp1 = 100, ar1 = 0, atk1 = 0;
    int hp2 = 100, ar2 = 2, atk2 = 8;
    int res = INT_MAX;
    for(int i=0;i<weapons.size();i++) {
        for(int j=0;j<armor.size();j++) {
            for(int k=0;k<rings.size();k++) {
                for(int l=k+1;l<rings.size();l++) {
                    ar1 = armor[j][2] + rings[k][2] + rings[l][2];
                    atk1 = weapons[i][1] + rings[k][1] + rings[l][1];
                    int tempHP1 = hp1, tempHP2 = hp2;
                    bool p1Turn = true;
                    while(tempHP1 > 0 && tempHP2 > 0) {
                        int dmg;
                        if(p1Turn) {
                            dmg = max(1, atk1 - ar2);
                            tempHP2 -= dmg;
                        }
                        else {
                            dmg = max(1, atk2 - ar1);
                            tempHP1 -= dmg;
                        }
                        p1Turn = !p1Turn;
                    }
                    if(tempHP1 > 0) res = min(res, weapons[i][0] + armor[j][0] + rings[k][0] + rings[l][0]);
                }
            }
        }
    }
    cout << res << endl;
}

void part2() {
    int hp1 = 100, ar1 = 0, atk1 = 0;
    int hp2 = 100, ar2 = 2, atk2 = 8;
    int res = 0;
    for(int i=0;i<weapons.size();i++) {
        for(int j=0;j<armor.size();j++) {
            for(int k=0;k<rings.size();k++) {
                for(int l=k+1;l<rings.size();l++) {
                    ar1 = armor[j][2] + rings[k][2] + rings[l][2];
                    atk1 = weapons[i][1] + rings[k][1] + rings[l][1];
                    int tempHP1 = hp1, tempHP2 = hp2;
                    bool p1Turn = true;
                    while(tempHP1 > 0 && tempHP2 > 0) {
                        int dmg;
                        if(p1Turn) {
                            dmg = max(1, atk1 - ar2);
                            tempHP2 -= dmg;
                        }
                        else {
                            dmg = max(1, atk2 - ar1);
                            tempHP1 -= dmg;
                        }
                        p1Turn = !p1Turn;
                    }
                    if(tempHP1 <= 0) res = max(res, weapons[i][0] + armor[j][0] + rings[k][0] + rings[l][0]);
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
