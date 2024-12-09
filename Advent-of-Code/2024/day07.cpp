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

void part1(vector<pair<ll, vector<ll>>> v) {
    int n = v.size();
    ll res = 0;
    for(int i=0;i<n;i++) {
        ll expected = v[i].first;
        vector<ll> nums = v[i].second;
        int numOperators = nums.size() - 1;
        for(int j=0;j<(1<<numOperators);j++) {
            bitset<32> bits(j);
            string bitString = bits.to_string().substr(32 - numOperators);
            //cout << bitString << endl;
            ll actual = nums[0];
            for(int k=0;k<bitString.size();k++) {
                if(bitString[k] == '1') {
                    // 1 = Add
                    actual = actual + nums[k+1];
                }
                else {
                    // 0 = Multiply
                    actual = actual * nums[k+1];
                }
            }
            if(expected == actual) {
                //cout << expected << endl;
                res += expected;
                break;
            }
        }
    }
    cout << res << endl;
}

void part2(vector<pair<ll, vector<ll>>> v) {
    int n = v.size();
    ll res = 0;
    for(int i=0;i<n;i++) {
        ll expected = v[i].first;
        vector<ll> nums = v[i].second;
        int numOperators = nums.size() - 1;
        int z = pow(3, numOperators);
        for(int j=0;j<z;j++) {
            string ternaryString(numOperators, '0');
            int x = j;
            int idx = numOperators - 1;
            while(x) {
                if(x % 3 == 0) {
                    ternaryString[idx] = '0';
                }
                else if(x % 3 == 1) {
                    ternaryString[idx] = '1';
                }
                else {
                    ternaryString[idx] = '2';
                }
                x /= 3;
                idx--;
            }
            //cout << ternaryString << endl;
            ll actual = nums[0];
            for(int k=0;k<numOperators;k++) {
                if(ternaryString[k] == '2') {
                    // 2 = Concat
                    actual = stol(to_string(actual) + to_string(nums[k+1]));
                }
                else if(ternaryString[k] == '1') {
                    // 1 = Add
                    actual = actual + nums[k+1];
                }
                else {
                    // 0 = Multiply
                    actual = actual * nums[k+1];
                }
            }
            if(expected == actual) {
                res += expected;
                break;
            }
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<pair<ll, vector<ll>>> v;
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, ": ");
        vector<string> b = tokenize(a[1], " ");
        vector<ll> c;
        for(string x : b) {
            c.push_back(stol(x));
        }
        v.push_back({stol(a[0]), c});
    }
    //part1(v);
    part2(v);
    return 0;
}
