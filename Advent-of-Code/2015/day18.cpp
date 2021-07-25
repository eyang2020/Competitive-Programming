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

int n, m;
vector<vector<char>> grid;

int calc(int i, int j) {
    bool left = (j - 1 >= 0), right = (j + 1 < m), down = (i + 1 < n), up = (i - 1 >= 0);
    int res = 0;
    if(left) {
        res += grid[i][j-1] == '#';
    }
    if(right) {
        res += grid[i][j+1] == '#';
    }
    if(up) {
        res += grid[i-1][j] == '#';
    }
    if(down) {
        res += grid[i+1][j] == '#';
    }
    if(left && up) {
        res += grid[i-1][j-1] == '#';
    }
    if(right && up) {
        res += grid[i-1][j+1] == '#';
    }
    if(left && down) {
        res += grid[i+1][j-1] == '#';
    }
    if(right && down) {
        res += grid[i+1][j+1] == '#';
    }
    return res;
}

void part1() {
    string s;
    while(getline(cin, s)) {
        vector<char> row;
        for(auto c : s) row.push_back(c);
        grid.push_back(row);
    }
    n = grid.size();
    m = grid[0].size();

    for(int k=0;k<100;k++) {
        vector<vector<char>> temp(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[i][j] = grid[i][j];
                int cnt = calc(i, j);
                if(grid[i][j] == '#') {
                    if(cnt != 2 && cnt != 3) temp[i][j] = '.'; 
                }
                else {
                    if(cnt == 3) temp[i][j] = '#';
                }
            }
        }
        grid = temp;
    }

    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                res++;
            }
        }
    }
    cout << res << endl;
}

void part2() {
    string s;
    while(getline(cin, s)) {
        vector<char> row;
        for(auto c : s) row.push_back(c);
        grid.push_back(row);
    }
    n = grid.size();
    m = grid[0].size();

    grid[0][0] = '#';
    grid[0][m-1] = '#';
    grid[n-1][0] = '#';
    grid[n-1][m-1] = '#';

    for(int k=0;k<100;k++) {
        vector<vector<char>> temp(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[i][j] = grid[i][j];
                int cnt = calc(i, j);
                if(grid[i][j] == '#') {
                    if(cnt != 2 && cnt != 3) temp[i][j] = '.'; 
                }
                else {
                    if(cnt == 3) temp[i][j] = '#';
                }
            }
        }
        grid = temp;
        grid[0][0] = '#';
        grid[0][m-1] = '#';
        grid[n-1][0] = '#';
        grid[n-1][m-1] = '#';
    }

    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') {
                res++;
            }
        }
    }
    cout << res << endl;
}

int main()
{
    IOS
    part1();
    //part2();
    return 0;
}
