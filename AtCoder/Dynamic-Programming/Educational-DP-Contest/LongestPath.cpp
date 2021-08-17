#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

// let dp[i] represent the longest path starting from node i
vector<int> dp(N);
vector<vector<int>> adj(N);

int dfs(int x) {
    if(dp[x]) {
        return dp[x];
    }
    for(auto next : adj[x]) {
        dp[next] = dfs(next);
        dp[x] = max(dp[x], dp[next] + 1);
    }
    return dp[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++) {
        if(!dp[i]) {
            dfs(i);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
