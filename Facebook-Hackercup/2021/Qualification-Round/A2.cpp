#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e6;
const int N = 2e5 + 5;
const ll MOD = 1e9+7;

int caseNum = 1;

void solve() {
    string s;
    int k, res = INF;
    cin >> s >> k;
    vector<vector<int>> dist(26, vector<int>(26, INF));
    for(int i=0;i<26;i++) dist[i][i] = 0;
    for(int i=0;i<k;i++) {
        char c1, c2;
        cin >> c1 >> c2;
        dist[c1-'A'][c2-'A'] = 1;
    }
    for(int k=0;k<26;k++) {
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i=0;i<26;i++) {
        int cur = 0;
        for(auto c : s) {
            cur += dist[c-'A'][i];
        }
        res = min(res, cur);
    }
    if(res == INF) res = -1;
    cout << "Case #" << caseNum++ << ':' << res << endl;
}

int main()  
{
    IOS
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}
