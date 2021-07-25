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

int cntOcc(int i, int j) {
    int cnt = 0;
    if(i - 1 >= 0) {
        cnt += (grid[i-1][j] == '#');
    }
    if(j - 1 >= 0) {
        cnt += (grid[i][j-1] == '#');
    }
    if(i + 1 < n) {
        cnt += (grid[i+1][j] == '#');
    }
    if(j + 1 < m) {
        cnt += (grid[i][j+1] == '#');
    }
    if(i + 1 < n && j + 1 < m) {
        cnt += (grid[i+1][j+1] == '#');
    }
    if(i - 1 >= 0 && j - 1 >= 0) {
        cnt += (grid[i-1][j-1] == '#');
    }
    if(i - 1 >= 0 && j + 1 < m) {
        cnt += (grid[i-1][j+1] == '#');
    }
    if(i + 1 < n && j - 1 >= 0) {
        cnt += (grid[i+1][j-1] == '#');
    }
    return cnt;
}

int cntOcc2(int i, int j) {
    int cnt = 0;
    // up
    for(int i2=i-1;i2>=0;i2--) {
        if(grid[i2][j] != '.') {
            if(grid[i2][j] == '#') cnt++;
            break;
        }
    }
    // down
    for(int i2=i+1;i2<n;i2++) {
        if(grid[i2][j] != '.') {
            if(grid[i2][j] == '#') cnt++;
            break;
        }
    }
    // left
    for(int j2=j-1;j2>=0;j2--) {
        if(grid[i][j2] != '.') {
            if(grid[i][j2] == '#') cnt++;
            break;
        }
    }
    // right
    for(int j2=j+1;j2<m;j2++) {
        if(grid[i][j2] != '.') {       
            if(grid[i][j2] == '#') cnt++;
            break;
        }
    }
    // up & right
    for(int i2=i-1,j2=j+1;i2>=0&&j2<m;i2--,j2++) {
        if(grid[i2][j2] != '.') {
            if(grid[i2][j2] == '#') cnt++;
            break;
        }
    }
    // up & left
    for(int i2=i-1,j2=j-1;i2>=0&&j2>=0;i2--,j2--) {
        if(grid[i2][j2] != '.') {
            if(grid[i2][j2] == '#') cnt++;
            break;
        }
    }   
    // down && right
    for(int i2=i+1,j2=j+1;i2<n&&j2<m;i2++,j2++) {
        if(grid[i2][j2] != '.') {
            if(grid[i2][j2] == '#') cnt++;
            break;
        }
    }
    // down && left 
    for(int i2=i+1,j2=j-1;i2<n&&j2>=0;i2++,j2--) {
        if(grid[i2][j2] != '.') {
            if(grid[i2][j2] == '#') cnt++;
            break;
        }
    }
    return cnt;
}

void part1() {
    string s;
    int idx = 0;
    while(getline(cin, s)) {
        grid.push_back({});
        m = s.size();
        for(int i=0;i<m;i++) {
            grid[idx].push_back(s[i]);
        }
        idx++;
    }
    n = grid.size();
    int res = 0;
    bool changed = true;
    while(changed) {
        changed = false;
        vector<vector<char>> next(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                next[i][j] = grid[i][j];
                int cnt = cntOcc(i, j);
                if(grid[i][j] == 'L') {
                    if(cnt == 0) {
                        changed = true;
                        next[i][j] = '#';
                    }
                }
                else if(grid[i][j] == '#') {
                    if(cnt >= 4) {
                        changed = true;
                        next[i][j] = 'L';
                    }
                }
            }
        }   
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                grid[i][j] = next[i][j];
            }
        }
    }
    /*for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)  {
            cout << grid[i][j];
        }
        cout << endl;
    }*/
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') res++;
        }
    }
    cout << res << endl;
    return;
} 

void part2() {
    string s;
    int idx = 0;
    while(getline(cin, s)) {
        grid.push_back({});
        m = s.size();
        for(int i=0;i<m;i++) {
            grid[idx].push_back(s[i]);
        }
        idx++;
    }
    n = grid.size();
    int res = 0;
    bool changed = true;
    while(changed) {
        changed = false;
        vector<vector<char>> next(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                next[i][j] = grid[i][j];
                int cnt = cntOcc2(i, j);
                if(grid[i][j] == 'L') {
                    if(cnt == 0) {
                        changed = true;
                        next[i][j] = '#';
                    }
                }
                else if(grid[i][j] == '#') {
                    if(cnt >= 5) {
                        changed = true;
                        next[i][j] = 'L';
                    }
                }
            }
        }   
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                grid[i][j] = next[i][j];
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') res++;
        }
    }
    /*for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)  {
            cout << grid[i][j];
        }
        cout << endl;
    }*/
    cout << res << endl;
    return;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
