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
    vector<vector<string>> v;
    while(getline(cin, s)) {
        vector<string> cur;
        string op = s.substr(0, s.find(" "));
        cur.push_back(op);
        s = s.substr(s.find(" ") + 1);
        if(op == "jie" || op == "jio") {
            string r = s.substr(0, s.find(","));
            s = s.substr(s.find(",") + 2);
            cur.push_back(r);
        }
        cur.push_back(s);
        v.push_back(cur);
    }
    int n = v.size();
    int idx = 0;
    int a = 0, b = 0;
    while(0 <= idx && idx < n) {
        vector<string> cur = v[idx];
        string op = cur[0];
        if(op == "hlf") {
            if(cur[1] == "a") a /= 2;
            else b /= 2; 
        }
        else if(op == "tpl") {
            if(cur[1] == "a") a *= 3;
            else b *= 3; 
        }
        else if(op == "inc") {
            if(cur[1] == "a") a++;
            else b++; 
        }
        else if(op == "jmp") {
            string mv = cur[1];
            int val = stoi(mv.substr(1));
            if(mv[0] == '-') val = -val;
            idx += val;
            continue;
        }
        else if(op == "jie") {
            int regVal = 0;
            if(cur[1] == "a") regVal = a;
            else regVal = b;
            if(regVal % 2 == 0) {
                string mv = cur[2];
                int val = stoi(mv.substr(1));
                if(mv[0] == '-') val = -val;
                idx += val;
                continue;
            }
        }
        else {
            int regVal = 0;
            if(cur[1] == "a") regVal = a;
            else regVal = b;
            if(regVal == 1) {
                string mv = cur[2];
                int val = stoi(mv.substr(1));
                if(mv[0] == '-') val = -val;
                idx += val;
                continue;
            }
        }
        idx++;
    }
    cout << a << ' ' << b << endl;
}

void part2() {
    string s;
    vector<vector<string>> v;
    while(getline(cin, s)) {
        vector<string> cur;
        string op = s.substr(0, s.find(" "));
        cur.push_back(op);
        s = s.substr(s.find(" ") + 1);
        if(op == "jie" || op == "jio") {
            string r = s.substr(0, s.find(","));
            s = s.substr(s.find(",") + 2);
            cur.push_back(r);
        }
        cur.push_back(s);
        v.push_back(cur);
    }
    int n = v.size();
    int idx = 0;
    int a = 1, b = 0;
    while(0 <= idx && idx < n) {
        vector<string> cur = v[idx];
        string op = cur[0];
        if(op == "hlf") {
            if(cur[1] == "a") a /= 2;
            else b /= 2; 
        }
        else if(op == "tpl") {
            if(cur[1] == "a") a *= 3;
            else b *= 3; 
        }
        else if(op == "inc") {
            if(cur[1] == "a") a++;
            else b++; 
        }
        else if(op == "jmp") {
            string mv = cur[1];
            int val = stoi(mv.substr(1));
            if(mv[0] == '-') val = -val;
            idx += val;
            continue;
        }
        else if(op == "jie") {
            int regVal = 0;
            if(cur[1] == "a") regVal = a;
            else regVal = b;
            if(regVal % 2 == 0) {
                string mv = cur[2];
                int val = stoi(mv.substr(1));
                if(mv[0] == '-') val = -val;
                idx += val;
                continue;
            }
        }
        else {
            int regVal = 0;
            if(cur[1] == "a") regVal = a;
            else regVal = b;
            if(regVal == 1) {
                string mv = cur[2];
                int val = stoi(mv.substr(1));
                if(mv[0] == '-') val = -val;
                idx += val;
                continue;
            }
        }
        idx++;
    }
    cout << a << ' ' << b << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
