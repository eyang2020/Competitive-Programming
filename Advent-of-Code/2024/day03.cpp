#include <bits/stdc++.h>
#include <regex>

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

void part1(string subject) {
    regex re("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    ll res = 0;
    for(sregex_iterator it = sregex_iterator(subject.begin(), subject.end(), re);
        it != sregex_iterator(); it++) {
        smatch match;
        match = *it;
        string s = match.str(0);
        vector<string> a = tokenize(s, ",");
        vector<string> b = tokenize(a[0], "(");
        vector<string> c = tokenize(a[1], ")");
        res += stol(b[1]) * stol(c[0]);
    }
    cout << res << endl;
}

void part2(string subject) {
    regex re("mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don\'t\\(\\)");
    ll res = 0;
    bool doFlag = true;
    for(sregex_iterator it = sregex_iterator(subject.begin(), subject.end(), re);
        it != sregex_iterator(); it++) {
        smatch match;
        match = *it;
        //cout << match.str(0) << endl;
        string s = match.str(0);
        if(s == "do()") {
            doFlag = true;
        }
        else if(s == "don't()") {
            doFlag = false;
        }
        else {
            if(doFlag) {
                vector<string> a = tokenize(s, ",");
                vector<string> b = tokenize(a[0], "(");
                vector<string> c = tokenize(a[1], ")");
                res += stol(b[1]) * stol(c[0]);
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s, x;
    while(getline(cin, x)) {
        s += x;
    }
    part1(s);
    part2(s);
    return 0;
}
