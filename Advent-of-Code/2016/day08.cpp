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
    vector<vector<char>> grid(6, vector<char>(50, '.'));
    string s;
    while(getline(cin, s)) {
        string op = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        if(op == "rect") {
            int a = stoi(s.substr(0, s.find("x")));
            s = s.substr(s.find("x") + 1);
            int b = stoi(s);
            for(int i=0;i<b;i++) {
                for(int j=0;j<a;j++) {
                    grid[i][j] = '#';
                }
            }
        }
        else {
            string op2 = s.substr(0, s.find(" "));
            s = s.substr(s.find("=") + 1);
            int pos = stoi(s.substr(0, s.find("by")));
            s = s.substr(s.find("by") + 3);
            int x = stoi(s);
            if(op2 == "row") {
                vector<char> temp = grid[pos];
                for(int j=0;j<50;j++) {
                    grid[pos][(j + x) % 50] = temp[j]; 
                }
            }
            else {
                vector<char> temp(6);
                for(int i=0;i<6;i++) {
                    temp[i] = grid[i][pos];
                }
                for(int i=0;i<6;i++) {
                    grid[(i + x) % 6][pos] = temp[i]; 
                }
            }
        }
    }
    int res = 0;
    for(auto row : grid) {
        for(auto c : row) {
            cout << c;
            if(c == '#') res++;
        }
        cout << endl;
    }
    cout << res << endl;
}

void part2() {
    /*
    .##..####.###..#..#.###..####.###....##.###...###.
    #..#.#....#..#.#..#.#..#....#.#..#....#.#..#.#....
    #..#.###..###..#..#.#..#...#..###.....#.#..#.#....
    ####.#....#..#.#..#.###...#...#..#....#.###...##..
    #..#.#....#..#.#..#.#....#....#..#.#..#.#.......#.
    #..#.#....###...##..#....####.###...##..#....###..
    */
}

int main()
{
    IOS
    part1();
    //part2();
    return 0;
}
