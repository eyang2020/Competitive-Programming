#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> graph(n);
        for(auto road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(vector<vector<pair<ll, ll>>> &graph, int n, int src) {
        vector<ll> dist(n, 1e18);
        vector<ll> dp(n);
        dp[src] = 1;
        dist[src] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> minHeap;
        minHeap.push({0, 0}); // {dist, src}
        
        while(!minHeap.empty()) {
            auto[d, u] = minHeap.top();
            minHeap.pop();
            if(d > dist[u]) continue;
            for(auto[v, t] : graph[u]) {
                if(dist[v] > d + t) {
                    dist[v] = dist[u] + t;
                    dp[v] = dp[u];
                    minHeap.push({dist[v], v});
                }
                else if(dist[v] == d + t) {
                    dp[v] = (dp[v] + dp[u]) % MOD;
                }
            }
        }
        
        return dp[n-1];
    }
};
