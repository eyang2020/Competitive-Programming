#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int t2 = 1;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<bool> rowOk(n, true), colOk(n, true);
    vector<int> rowCnt(n), colCnt(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'O') {
                rowOk[i] = false;
                colOk[j] = false;
            }
            else if(grid[i][j] == 'X') {
                rowCnt[i]++;
                colCnt[j]++;
            }
        }
    }
    int mn = 1e9, ways = 0;
    for(int i=0;i<n;i++) {
        if(rowOk[i]) {
            mn = min(mn, n - rowCnt[i]);
        }
        if(colOk[i]) {
            mn = min(mn, n - colCnt[i]);
        }
    }
    if(mn == 1e9) cout << "Case #" << t2++ << ": " << "Impossible" << endl;
    else {
        vector<vector<bool>> vis(n, vector<bool>(n, true));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '.') vis[i][j] = false;
            }
        }
        for(int i=0;i<n;i++) {
            if(rowOk[i] && n - rowCnt[i] == mn) {
                bool ok = false;
                for(int j=0;j<n;j++) {
                    if(!vis[i][j]) {
                        vis[i][j] = true;
                        ok = true;
                    }
                } 
                if(ok) ways++;
            }
            if(colOk[i] && n - colCnt[i] == mn) {
                bool ok = false;
                for(int j=0;j<n;j++) {
                    if(!vis[j][i]) {
                        vis[j][i] = true;
                        ok = true;
                    }
                } 
                if(ok) ways++;
            }
        }
        if(mn == n) ways++;
        cout << "Case #" << t2++ << ": " << mn << ' ' << ways << endl;
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
