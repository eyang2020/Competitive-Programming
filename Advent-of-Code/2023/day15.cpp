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

int hashFunc(string s) {
    int n = s.length(), res = 0;
    for(int i=0;i<n;i++) {
        res += (int)s[i];
        res *= 17;
        res %= 256;
    }
    return res;
}

void part1(vector<string> tokens) {
    int n = tokens.size(), res = 0;
    for(int i=0;i<n;i++) {
        res += hashFunc(tokens[i]);
    }
    cout << res << endl;
}

void part2(vector<string> tokens) {
    int n = tokens.size(), res = 0;
    vector<vector<pair<string, int>>> boxes(256);
    for(int i=0;i<n;i++) {
        string token = tokens[i];
        if(token.find('=') != string::npos) {
            vector<string> v = tokenize(token, "=");
            string label = v[0];
            int focalLength = stoi(v[1]);
            int boxNumber = hashFunc(label);
            vector<pair<string, int>> &box = boxes[boxNumber];
            int m = box.size();
            bool found = false;
            for(int j=0;j<m;j++) {
                if(box[j].first == label) {
                    box[j] = {label, focalLength};
                    found = true;
                    break;
                }
            }
            if(!found) {
                box.push_back({label, focalLength});
            }
        }
        else {
            vector<string> v = tokenize(token, "-");
            string label = v[0];
            int boxNumber = hashFunc(label);
            vector<pair<string, int>> &box = boxes[boxNumber];
            int m = box.size();
            for(int j=0;j<m;j++) {
                if(box[j].first == label) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    int m = boxes.size();
    for(int i=0;i<m;i++) {
        vector<pair<string, int>> box = boxes[i];
        int k = box.size();
        for(int j=0;j<k;j++) {
            pair<string, int> lens = box[j];
            res += (i + 1) * (j + 1) * (lens.second);
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    cin >> s;
    vector<string> tokens = tokenize(s, ",");
    part1(tokens);
    part2(tokens);
    return 0;
}
