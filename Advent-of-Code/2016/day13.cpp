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

int f(int x, int y) {
    return x*x + 3*x + 2*x*y + y + y*y;
}

void part1() {
    int k;
    cin >> k;
    int n = 100, m = 100;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int cur = f(j, i) + k, cnt = __builtin_popcount(cur);
            grid[i][j] = ((cnt % 2 == 0) ? '.' : '#');
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vis[1][1] = true;
    dist[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int y = f.first, x = f.second;
        if(y == 39 && x == 31) {
            cout << dist[y][x] << endl;
            break;
        }
        for(int i=0;i<4;i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m && grid[nextY][nextX] == '.' && !vis[nextY][nextX]) {
                q.push({nextY, nextX});
                vis[nextY][nextX] = true;
                dist[nextY][nextX] = min(dist[nextY][nextX], 1 + dist[y][x]);
            }
        }
    }
}

void part2() {
    int k;
    cin >> k;
    int n = 100, m = 100;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int cur = f(j, i) + k, cnt = __builtin_popcount(cur);
            grid[i][j] = ((cnt % 2 == 0) ? '.' : '#');
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vis[1][1] = true;
    dist[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int y = f.first, x = f.second;
        for(int i=0;i<4;i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(0 <= nextY && nextY < n && 0 <= nextX && nextX < m && grid[nextY][nextX] == '.' && !vis[nextY][nextX]) {
                q.push({nextY, nextX});
                vis[nextY][nextX] = true;
                dist[nextY][nextX] = min(dist[nextY][nextX], 1 + dist[y][x]);
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist[i][j] <= 50) res++;
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
