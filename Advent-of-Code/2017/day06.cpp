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

string Hash(vector<int> a) {
    string res;
    for(auto x : a) {
        res += to_string(x) + '|';
    }
    return res.substr(0, res.length() - 1);
}

void part1() {
    string s;
    getline(cin, s);
    vector<int> a;
    string cur;
    for(auto c : s) {
        if(c == '\t') {
            if(cur.length() > 0) {
                a.push_back(stoi(cur));
                cur = "";
            }
        }
        else cur += c;
    }
    if(cur.length() > 0) a.push_back(stoi(cur));
    int n = a.size();
    set<string> st;
    st.insert(Hash(a));
    int res = 0;
    while(true) {
        res++;
        int mx = 0;
        int idx = 0;
        for(int i=0;i<n;i++) {
            if(a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }
        a[idx] = 0;
        int add = mx / n;
        for(int i=0;i<n;i++) a[i] += add;
        add = mx % n;
        for(int i=0;i<add;i++) {
            a[(idx+i+1)%n]++;
        }
        string next = Hash(a);
        if(st.count(next)) break;
        st.insert(next);
    }
    cout << res << endl;
}

void part2() {
    string s;
    getline(cin, s);
    vector<int> a;
    string cur;
    for(auto c : s) {
        if(c == '\t') {
            if(cur.length() > 0) {
                a.push_back(stoi(cur));
                cur = "";
            }
        }
        else cur += c;
    }
    if(cur.length() > 0) a.push_back(stoi(cur));
    int n = a.size();
    map<string, int> cnt;
    map<string, int> last;
    cur = Hash(a);
    cnt[cur]++;
    last[cur] = 1;
    int res = 0;
    while(true) {
        res++;
        int mx = 0;
        int idx = 0;
        for(int i=0;i<n;i++) {
            if(a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }
        a[idx] = 0;
        int add = mx / n;
        for(int i=0;i<n;i++) a[i] += add;
        add = mx % n;
        for(int i=0;i<add;i++) {
            a[(idx+i+1)%n]++;
        }
        string next = Hash(a);
        if(cnt[next] == 2) {
            res = res - last[next];
            break;
        }
        cnt[next]++;
        last[next] = res;
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
