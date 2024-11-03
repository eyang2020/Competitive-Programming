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

const string maps[7] = {
    "seed-to-soil map:",
    "soil-to-fertilizer map:",
    "fertilizer-to-water map:",
    "water-to-light map:",
    "light-to-temperature map:",
    "temperature-to-humidity map:",
    "humidity-to-location map:"
};

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

ll getDestinationFromSource(ll key, pair<ll, ll> source, ll destination) {
    if(source.first <= key && key <= source.second) {
        return destination + key - source.first;
    }
    return key;
}

void part1(vector<ll> seeds, map<string, vector<vector<ll>>> mp) {
    ll res = -1;
    for(ll seed : seeds) {
        for(int i=0;i<size(maps);i++) {
            vector<vector<ll>> a = mp[maps[i]];
            for(vector<ll> b : a) {
                ll destination = b[0], source = b[1], length = b[2];
                ll next = getDestinationFromSource(seed, {source, source + length - 1}, destination);
                if(next != seed) {
                    seed = next;
                    break;
                }
            }
        }
        if(res == -1) {
            res = seed;
        }
        else {
            res = min(res, seed);
        }
    }
    cout << res << endl;
}

void part2(vector<ll> seeds, map<string, vector<vector<ll>>> mp) {

}

int main() {
    IOS
    string s;
    getline(cin, s);
    vector<string> a = tokenize(tokenize(s, ": ")[1], " ");
    vector<ll> seeds;
    for(auto x : a) {
        seeds.push_back(stol(x));
    }
    map<string, vector<vector<ll>>> mp;
    getline(cin, s);
    while(getline(cin, s)) {
        vector<vector<ll>> a1;
        string s1;
        while(getline(cin, s1)) {
            if(s1.length() == 0) {
                break;
            }
            vector<string> b = tokenize(s1, " ");
            vector<ll> c;
            for(auto x : b) {
                c.push_back(stol(x));
            }
            a1.push_back(c);
        }
        mp[s] = a1;
    }
    part1(seeds, mp);
    part2(seeds, mp);
    return 0;
}
