#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const ll MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
int main() {
    IOS
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') x1 = i, y1 = j;
            else if(grid[i][j] == 'B') x2 = i, y2 = j;
        }
    }
    queue<pair<int, int>> q;
    q.push({x1, y1});
    grid[x1][y1] = '#';
    dist[x1][y1] = 0;
    while(!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int x = f.first, y = f.second;
        if(x == x2 && y == y2) {
            int curDist = dist[x][y];
            cout << "YES" << endl;
            cout << curDist << endl;
            string res;
            while(x != x1 || y != y1) {
                if(x > 0 && dist[x-1][y] == curDist - 1) {
                    res += 'D';
                    x--;
                }
                else if(x < n - 1 && dist[x+1][y] == curDist - 1) {
                    res += 'U';
                    x++;
                }
                else if(y > 0 && dist[x][y-1] == curDist - 1) {
                    res += 'R';
                    y--;
                }
                else {
                    res += 'L';
                    y++;
                }
                curDist--;
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
            return 0;
        }
        for(int i=0;i<4;i++) {
            int nextX = x + dx[i], nextY = y + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && grid[nextX][nextY] != '#') {
                q.push({nextX, nextY});
                grid[nextX][nextY] = '#';
                dist[nextX][nextY] = dist[x][y] + 1;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
