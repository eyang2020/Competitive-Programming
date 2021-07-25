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
    int x = 0, y = 0;
    int dir = 1; //  E=1, S=2, W=3, N=4
    string s;
    while(getline(cin, s)) {
        char c = s[0];
        int val = stoi(s.substr(1));
        if(c == 'N') {
            y += val;
        }
        else if(c == 'S') {
            y -= val;
        }
        else if(c == 'E') {
            x += val;
        }
        else if(c == 'W') {
            x -= val;
        }
        else if(c == 'L') {
            dir -= (val / 90);
            dir += 4;
            if(dir > 4) dir %= 4;
        }
        else if(c == 'R') {
            dir += (val / 90);
            if(dir > 4) dir %= 4;
        }
        else {
            if(dir == 1) {
                x += val;
            }
            else if(dir == 2) {
                y -= val;
            }
            else if(dir == 3) {
                x -= val;
            }
            else {
                y += val;
            }
        }
    }
    //cout << dir << endl;
    //cout << x << ' ' << y << endl;
    cout << abs(x) + abs(y) << endl;
    return;
} 

void part2() {
    int x1 = 0, y1 = 0; // ship
    int x2 = 10, y2 = 1; // waypoint
    string s;
    while(getline(cin, s)) {
        char c = s[0];
        int val = stoi(s.substr(1));
        if(c == 'N') {
            y2 += val;
        }
        else if(c == 'S') {
            y2 -= val;
        }
        else if(c == 'E') {
            x2 += val;
        }
        else if(c == 'W') {
            x2 -= val;
        }
        else if(c == 'L') {
            if(val == 90) {
                swap(x2, y2);
                x2 = -x2;
            }
            else if(val == 180) {
                x2 = -x2;
                y2 = -y2;
            }
            else if(val == 270) {
                swap(x2, y2);
                y2 = -y2;
            }
        }
        else if(c == 'R') {
            if(val == 270) {
                swap(x2, y2);
                x2 = -x2;
            }
            else if(val == 180) {
                x2 = -x2;
                y2 = -y2;
            }
            else if(val == 90) {
                swap(x2, y2);
                y2 = -y2;
            }
        }
        else {
            x1 += x2 * val;
            y1 += y2 * val;
        }
    }
    cout << abs(x1) + abs(y1) << endl;
    return;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
