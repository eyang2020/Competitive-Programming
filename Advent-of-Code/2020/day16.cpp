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
    map<string, vector<pair<ll, ll>>> mp;
    string s;
    while(getline(cin, s)) {
        if(s == "") {
            break;
        }
        string a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        string x = s.substr(0, s.find("or") - 1);
        string y = s.substr(s.find("or") + 3);
        //cout << a << endl;
        //cout << x << ' ' << y << endl;
        mp[a] = {};
        mp[a].push_back(make_pair(stol(x.substr(0, x.find("-"))), stol(x.substr(x.find("-") + 1))));
        mp[a].push_back(make_pair(stol(y.substr(0, y.find("-"))), stol(y.substr(y.find("-") + 1))));
    }
    /*for(auto p : mp) {
        auto v = p.second;
        for(auto pr : v) {
            cout << pr.first << ' ' << pr.second << endl;
        }
    }*/
    getline(cin, s);
    getline(cin, s); // my ticket read in
    string delim = ",";
    int pos = 0;
    vector<ll> myTicket;
    while((pos = s.find(delim)) != string::npos) {
        myTicket.push_back(stol(s.substr(0, pos)));
        s.erase(0, pos + delim.length());
    }
    if(s.length() > 0) {
        myTicket.push_back(stol(s));
    }
    //for(auto p : myTicket) cout << p << ' ';
    getline(cin, s);
    getline(cin, s);
    ll res = 0;
    while(getline(cin, s)) {
        vector<ll> ticket;
        int pos = 0;
        while((pos = s.find(delim)) != string::npos) {
            ticket.push_back(stol(s.substr(0, pos)));
            s.erase(0, pos + delim.length());
        }
        if(s.length() > 0) {
            ticket.push_back(stol(s));
        }
        for(auto cur : ticket) {
            bool ok = false;
            for(auto p1 : mp) {
                auto v = p1.second;
                for(auto p2 : v) {
                    ll l = p2.first, r = p2.second;
                    if(l <= cur && cur <= r) {
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok) {
                res += cur;
            }
        }
    }
    cout << res << endl;
}

void part2() {
    map<string, vector<pair<ll, ll>>> mp;
    string s;
    while(getline(cin, s)) {
        if(s == "") {
            break;
        }
        string a = s.substr(0, s.find(":"));
        s = s.substr(s.find(":") + 2);
        string x = s.substr(0, s.find("or") - 1);
        string y = s.substr(s.find("or") + 3);
        mp[a] = {};
        mp[a].push_back(make_pair(stol(x.substr(0, x.find("-"))), stol(x.substr(x.find("-") + 1))));
        mp[a].push_back(make_pair(stol(y.substr(0, y.find("-"))), stol(y.substr(y.find("-") + 1))));
    }
    getline(cin, s);
    getline(cin, s); // my ticket read in
    string delim = ",";
    int pos = 0;
    vector<ll> myTicket;
    while((pos = s.find(delim)) != string::npos) {
        myTicket.push_back(stol(s.substr(0, pos)));
        s.erase(0, pos + delim.length());
    }
    if(s.length() > 0) {
        myTicket.push_back(stol(s));
    }
    getline(cin, s);
    getline(cin, s);
    vector<vector<ll>> validTickets;
    while(getline(cin, s)) {
        vector<ll> ticket;
        int pos = 0;
        while((pos = s.find(delim)) != string::npos) {
            ticket.push_back(stol(s.substr(0, pos)));
            s.erase(0, pos + delim.length());
        }
        if(s.length() > 0) {
            ticket.push_back(stol(s));
        }
        bool ok1 = true;
        for(auto cur : ticket) {
            bool ok2 = false;
            for(auto p1 : mp) {
                auto v = p1.second;
                for(auto p2 : v) {
                    ll l = p2.first, r = p2.second;
                    if(l <= cur && cur <= r) {
                        ok2 = true;
                        break;
                    }
                }
                if(ok2) {
                    break;
                }
            }
            if(!ok2) {
                ok1 = false;
                break;
            }
        }
        if(ok1) {
            validTickets.push_back(ticket);
        }
    }
    int m = myTicket.size();
    vector<int> perm(m);
    for(int i=0;i<m;i++) perm[i] = i;
    vector<int> temp = {0, 2, 1};
    do {
        
    }
    while(next_permutation(perm.begin(), perm.end()));
    ll res = 1;
    for(auto p : mp) {
        string a = p.first;
        vector<pair<ll, ll>> b = p.second;
        if(a.find("departure") != string::npos) {
            
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
