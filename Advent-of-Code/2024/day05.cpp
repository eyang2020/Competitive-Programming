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

void topologicalSortUtil(int node, map<int, vector<int>> adj, vector<bool> &vis, stack<int> &stk) {
    vis[node] = true;
    for(int next : adj[node]) {
        if(!vis[next]) {
            topologicalSortUtil(next, adj, vis, stk);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<int> nodes, map<int, vector<int>> mp) {
    map<int, vector<int>> adj;
    vector<pair<int, int>> edges;
    for(int node : nodes) {
        vector<int> children = mp[node];
        for(int child : children) {
            if(find(nodes.begin(), nodes.end(), child) != nodes.end()) {
                edges.push_back({node, child});
            }
        }
    }
    for(auto i : edges) {
        adj[i.first].push_back(i.second);
    }
    stack<int> stk;
    vector<bool> vis(nodes.size(), false);
    for(int i=0;i<nodes.size();i++) {
        if(!vis[nodes[i]]) {
            topologicalSortUtil(nodes[i], adj, vis, stk);
        }
    }
    vector<int> res;
    while(!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

void part1(map<int, vector<int>> mp, vector<vector<int>> nums) {
    int res = 0;
    for(int k=0;k<nums.size();k++) {
        vector<int> v = nums[k];
        int n = v.size();
        bool ok = true;
        for(int i=0;i<n;i++) {
            vector<int> children = mp[v[i]];
            //for(auto p : children) cout << p << ' ';
            //cout << endl;
            for(int j=i+1;j<n;j++) {
                if(find(children.begin(), children.end(), v[j]) == children.end()) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) {
            //cout << k << endl;
            res += v[((n+1)/2-1)];
        }
    }
    cout << res << endl;
}

void part2(map<int, vector<int>> mp, vector<vector<int>> nums) {
    int res = 0;
    for(int k=0;k<nums.size();k++) {
        vector<int> v = nums[k];
        int n = v.size();
        bool ok = true;
        for(int i=0;i<n;i++) {
            vector<int> children = mp[v[i]];
            //for(auto p : children) cout << p << ' ';
            //cout << endl;
            for(int j=i+1;j<n;j++) {
                if(find(children.begin(), children.end(), v[j]) == children.end()) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) {
            //cout << k << endl;
            vector<int> vv = topologicalSort(v, mp);
            res += vv[((n+1)/2-1)];
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    map<int, vector<int>> mp; // Parent --> Children, where Parent needs to appear before all its Children
    vector<vector<int>> nums;
    while(getline(cin, s)) {
        if(s == "") break;
        vector<string> a = tokenize(s, "|");
        int x = stoi(a[0]), y = stoi(a[1]);
        mp[x].push_back(y);
    }
    while(getline(cin, s)) {
        vector<string> a = tokenize(s, ",");
        vector<int> b;
        for(int i=0;i<a.size();i++) {
            b.push_back(stoi(a[i]));
        }
        nums.push_back(b);
    }
    part1(mp, nums);
    part2(mp, nums);
    return 0;
}
