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

struct Event {
    string dateAndTime;
    int hr, mn;
    string act;
};

bool comp(Event e1, Event e2) {
    return e1.dateAndTime < e2.dateAndTime;
}

void part1() {
    string s;
    vector<Event> v;
    while(getline(cin, s)) {
        string dateAndTime = s.substr(1, s.find("]") - 1);
        s = s.substr(s.find("]") + 2);
        string temp = dateAndTime;
        int hr, mn;
        temp = temp.substr(temp.find(" ") + 1);
        hr = stoi(temp.substr(0, temp.find(":")));
        temp = temp.substr(temp.find(":") + 1);
        mn = stoi(temp);
        struct Event e = {dateAndTime, hr, mn, s};
        //cout << hr << ' ' << mn << endl;
        v.push_back(e);
    }
    sort(v.begin(), v.end(), comp);
    int guard = 0, lastMn = 0;
    map<int, vector<int>> mp1; // minutes cnt per guard
    map<int, int> mp2; // sleep length per guard
    for(auto e : v) {
        //out << e.dateAndTime << endl;
        string cur = e.act;
        if(cur[0] == 'G') { // new guard
            cur = cur.substr(cur.find("#") + 1);
            guard = stoi(cur.substr(0, cur.find(" ")));
            if(mp1.find(guard) == mp1.end()) {
                mp1[guard] = vector<int>(60);
            }
        }
        else if(cur[0] == 'f') { // falls asleep
            lastMn = e.mn;
        }
        else { // wakes up
            int curMn = e.mn; // '<' curMin bc wakes up at curMin
            for(int i=lastMn;i<curMn;i++) mp1[guard][i]++;
            mp2[guard] += curMn - lastMn;
        }
    }
    int res = 0;
    int mx = 0;
    int bestMn = 0;
    for(auto p : mp2) {
        int tot = p.second;
        if(tot > mx) {
            mx = tot;
            guard = p.first;
        }
    }
    vector<int> cnt = mp1[guard];
    mx = 0;
    for(int i=0;i<60;i++) {
        if(cnt[i] > mx) {
            mx = cnt[i];
            bestMn = i;
        }
    }
    res = guard * bestMn;
    cout << res << endl;
}

void part2() {
    string s;
    vector<Event> v;
    while(getline(cin, s)) {
        string dateAndTime = s.substr(1, s.find("]") - 1);
        s = s.substr(s.find("]") + 2);
        string temp = dateAndTime;
        int hr, mn;
        temp = temp.substr(temp.find(" ") + 1);
        hr = stoi(temp.substr(0, temp.find(":")));
        temp = temp.substr(temp.find(":") + 1);
        mn = stoi(temp);
        struct Event e = {dateAndTime, hr, mn, s};
        //cout << hr << ' ' << mn << endl;
        v.push_back(e);
    }
    sort(v.begin(), v.end(), comp);
    int guard = 0, lastMn = 0;
    map<int, vector<int>> mp1; // minutes cnt per guard
    map<int, int> mp2; // sleep length per guard
    for(auto e : v) {
        //out << e.dateAndTime << endl;
        string cur = e.act;
        if(cur[0] == 'G') { // new guard
            cur = cur.substr(cur.find("#") + 1);
            guard = stoi(cur.substr(0, cur.find(" ")));
            if(mp1.find(guard) == mp1.end()) {
                mp1[guard] = vector<int>(60);
            }
        }
        else if(cur[0] == 'f') { // falls asleep
            lastMn = e.mn;
        }
        else { // wakes up
            int curMn = e.mn; // '<' curMin bc wakes up at curMin
            for(int i=lastMn;i<curMn;i++) mp1[guard][i]++;
            mp2[guard] += curMn - lastMn;
        }
    }
    int mx = 0;
    int bestMn = 0;
    for(auto p : mp1) {
        int curGuard = p.first;
        vector<int> cnt = p.second;
        for(int i=0;i<60;i++) {
            if(cnt[i] > mx) {
                mx = cnt[i];
                bestMn = i;
                guard = curGuard;
            }
        }
    }
    int res = guard * bestMn;
    cout << res << endl;
}

int main()
{
    IOS
    //part1();
    part2();
    return 0;
}
