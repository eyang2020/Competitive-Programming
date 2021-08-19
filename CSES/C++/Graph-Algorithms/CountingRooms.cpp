#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;
const int N = 1005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<char>> grid(N, vector<char>(N));
vector<vector<bool>> vis(N, vector<bool>(N));

void dfs(int i, int j) {
    vis[i][j] = true;
    for(int k=0;k<4;k++) {
        int nextI = i + dx[k];
        int nextJ = j + dy[k];
        if(nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m && !vis[nextI][nextJ] && grid[nextI][nextJ] == '.') {
            dfs(nextI, nextJ);
        }
    }
}

int main() {
    IOS
    cin >> n >> m;
    int res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
