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
    map<string, int> mp;
    string s;
    while(getline(cin, s)) {
        if(s == "") break;
        string a = s.substr(0, s.find(":"));
        int b = stoi(s.substr(s.find(":") + 2));
        //cout << a << ' ' << b << endl;
        mp[a] = b;
    }
    vector<map<string, int>> v;
    while(getline(cin, s)) {
        map<string, int> temp;
        s = s.substr(s.find(":") + 2);
        string a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        int b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        s = s.substr(s.find(",") + 2);
        //cout << s << endl;
        a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        s = s.substr(s.find(",") + 2);
        //cout << s << endl;
        a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        //cout << s << endl;
        v.push_back(temp);
    }
    for(int i=0;i<500;i++) {
        map<string, int> cur = v[i];
        bool ok = true;
        for(auto p1 : mp) {
            string a1 = p1.first;
            int b1 = p1.second;
            if(cur.find(a1) == cur.end()) {
                continue;
            }
            if(cur[a1] != b1) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i + 1 << endl;
            return;
        }
    }
}

void part2() {
    map<string, int> mp;
    string s;
    while(getline(cin, s)) {
        if(s == "") break;
        string a = s.substr(0, s.find(":"));
        int b = stoi(s.substr(s.find(":") + 2));
        //cout << a << ' ' << b << endl;
        mp[a] = b;
    }
    vector<map<string, int>> v;
    while(getline(cin, s)) {
        map<string, int> temp;
        s = s.substr(s.find(":") + 2);
        string a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        int b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        s = s.substr(s.find(",") + 2);
        //cout << s << endl;
        a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        s = s.substr(s.find(",") + 2);
        //cout << s << endl;
        a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        b = stoi(s.substr(0, s.find(",")));
        temp[a] = b;
        //cout << s << endl;
        v.push_back(temp);
    }
    map<string, int> x = v[45];
    for(int i=0;i<500;i++) {
        map<string, int> cur = v[i];
        bool ok = true;
        for(auto p1 : mp) {
            string a1 = p1.first;
            int b1 = p1.second;
            if(cur.find(a1) == cur.end()) {
                continue;
            }
            if(a1 == "cats" || a1 == "trees") {
                if(cur[a1] <= b1) {
                    ok = false;
                    break;
                }
            }
            else if(a1 == "pomeranians" || a1 == "goldfish") {
                if(cur[a1] >= b1) {
                    ok = false;
                    break;
                }
            }
            else if(cur[a1] != b1) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
