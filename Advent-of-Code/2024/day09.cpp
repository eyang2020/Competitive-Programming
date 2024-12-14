#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int dxWithDiag[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dyWithDiag[8] = {1, 0, -1, 0, -1, 1, 1, -1};

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll modpow(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    if(x == 0) return 0;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

vector<string> tokenize(string s, string delim) {
    vector<string> tokens;
    int idx = 0, n = delim.length();
    string token;
    while((idx = s.find(delim)) != string::npos) {
        token = s.substr(0, idx);
        tokens.push_back(token);
        s.erase(0, idx + n);
    }
    tokens.push_back(s);
    return tokens;
}

void part1(string s) {
    int n = s.length();
    int id = 0;
    bool isFree = false;
    vector<string> v;
    for(int i=0;i<n;i++) {
        char c = s[i];
        int d = c - '0';
        if(isFree) {
            for(int j=0;j<d;j++) {
                v.push_back(".");
            }
        }
        else {
            for(int j=0;j<d;j++) {
                v.push_back(to_string(id));
            }
            id++;
        }
        isFree = !isFree;
    }
    int m = v.size(), l = 0, r = m - 1;
    while(l < r) {
        if(v[l] == ".") {
            while(l < r && v[r] == ".") {
                r--;
            }
            v[l] = v[r];
            v[r] = '.';
            l++;
            r--;
        }
        else {
            l++;
        }
    }
    //for(auto x : v) cout << x << endl;
    ll checkSum = 0;
    for(int i=0;i<v.size();i++) {
        if(v[i] != ".") {
            checkSum += i * stol(v[i]);
        }
    }
    cout << checkSum << endl;
}

void part2(string s) {
    int n = s.length();
    int id = 0;
    bool isFree = false;
    vector<pair<int, string>> v;
    for(int i=0;i<n;i++) {
        char c = s[i];
        int d = c - '0';
        if(isFree) {
            v.push_back({d, "."});
        }
        else {
            v.push_back({d, to_string(id)});
            id++;
        }
        isFree = !isFree;
    }
    for(int curId=id-1;curId>=0;curId--) {
        int l = 0, r = v.size() - 1;
        string curIdStr = to_string(curId);
        while(l < r) {
            if(v[r].second == curIdStr) {
                while(l < r && (v[l].second != "." || v[l].first < v[r].first)) {
                    l++;
                }
                if(l != r && v[l].first >= v[r].first) {
                    if(v[l].first == v[r].first) {
                        v[l] = {v[r].first, v[r].second};
                        v[r] = {v[l].first, "."};
                    }
                    else {
                        v[l] = {v[l].first - v[r].first, v[l].second};
                        v.insert(v.begin() + l, {v[r].first, v[r].second});
                        v[r+1] = {v[r+1].first, "."};
                    }
                    break;
                }
            }
            else {
                r--;
            }
        }
        vector<pair<int, string>> v2;
        int idx = 0;
        while(idx < v.size()) {
            if(v[idx].second != ".") {
                v2.push_back(v[idx]);
                idx++; 
            }
            else {
                int sum = 0;
                while(v[idx].second == ".") {
                    sum += v[idx].first;
                    idx++;
                }
                v2.push_back({sum, "."});
            }
        }
        v = v2;
        // for(auto p : v) {
        //     cout << p.first << ' ' << p.second << endl;
        // }
        // cout << endl;
    }
    vector<string> res;
    for(auto p : v) {
        int len = p.first;
        string val = p.second;
        for(int i=0;i<len;i++) {
            res.push_back(val);
        }
    }
    //for(auto x : res) cout << x << endl;
    ll checkSum = 0;
    for(int i=0;i<res.size();i++) {
        if(res[i] != ".") {
            checkSum += i * stol(res[i]);
        }
    }
    cout << checkSum << endl;
}

int main() {
    IOS
    string s;
    cin >> s;
    part1(s);
    part2(s);
    return 0;
}
