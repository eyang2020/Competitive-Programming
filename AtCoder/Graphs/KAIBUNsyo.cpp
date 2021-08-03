#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 2e5 + 5;
 
vector<int> a(N);
vector<vector<int>> adj(N);
vector<bool> vis(N);
 
void dfs(int v) {
    if(!vis[v]) return;
    vis[v] = false;
    for(auto next : adj[v]) dfs(next);
}
 
int main() {
    int n, res = 0;
    cin >> n;
    // res = number of distinct elements in array a
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(!vis[a[i]]) {
            vis[a[i]] = true;
            res++;
        }
    }
    // create connected components based on palindromic positions
    int i = 0, j = n - 1;
    while(i < j) {
        adj[a[i]].push_back(a[j]);
        adj[a[j]].push_back(a[i]);
        i++, j--;
    } 
    // subtract the number of connected components from res
    for(int i=1;i<N;i++) {
        if(vis[i]) {
            res--;
            dfs(i);
        }
    }
    cout << res << endl;
}
