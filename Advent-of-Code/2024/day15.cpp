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

pair<int, int> getStartingPos(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    pair<int, int> pos;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '@') {
                pos = {i, j};
            }
        }
    }
    return pos;
}

bool inBounds(vector<vector<char>> grid, int y, int x) {
    int n = grid.size(), m = grid[0].size();
    return ((0 <= y && y < n) && (0 <= x && x < m) && (grid[y][x] != '#'));
}

void printGrid(vector<vector<char>> grid) {
    for(auto v : grid) {
        for(auto c : v) {
            cout << c;
        }
        cout << endl;
    }
    cout << endl;
}

void simulateMoves(vector<vector<char>> &grid, string moves) {
    int n = grid.size(), m = grid[0].size();
    pair<int, int> pos = getStartingPos(grid);
    int curY = pos.first, curX = pos.second;
    for(char c : moves) {
        int nextY = curY, nextX = curX;
        if(c == '^') {
            nextY--;
            while(nextY >= 0 && grid[nextY][nextX] == 'O') {
                nextY--;
            }
            if(inBounds(grid, nextY, curX)) {
                for(int i=nextY;i<curY;i++) {
                    grid[i][curX] = grid[i+1][curX];
                    grid[i+1][curX] = '.';
                }
                curY--;
            }
        }
        else if(c == 'v') {
            nextY++;
            while(nextY < n && grid[nextY][curX] == 'O') {
                nextY++;
            }
            if(inBounds(grid, nextY, curX)) {
                for(int i=nextY;i>curY;i--) {
                    grid[i][curX] = grid[i-1][curX];
                    grid[i-1][curX] = '.';
                }
                curY++;
            }
        }
        else if(c == '<') {
            nextX--;
            while(nextX >= 0 && grid[nextY][nextX] == 'O') {
                nextX--;
            }
            if(inBounds(grid, curY, nextX)) {
                for(int i=nextX;i<curX;i++) {
                    grid[curY][i] = grid[curY][i+1];
                    grid[curY][i+1] = '.';
                }
                curX--;
            }
        }
        else {
            nextX++;
            while(nextX < m && grid[nextY][nextX] == 'O') {
                nextX++;
            }
            if(inBounds(grid, curY, nextX)) {
                for(int i=nextX;i>curX;i--) {
                    grid[curY][i] = grid[curY][i-1];
                    grid[curY][i-1] = '.';
                }
                curX++;
            }
        }
        //printGrid(grid);
    }
}

pair<int, int> move(vector<vector<char>> &grid, char move, pair<int, int> pos) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<pair<int, int>>> neighbors;
    set<pair<int, int>> st;
    queue<pair<int, int>> q;
    q.push(pos);
    while(!q.empty()) {
        int queueSize = q.size();
        vector<pair<int, int>> level;
        for(int i=0;i<queueSize;i++) {
            pair<int, int> f = q.front();
            q.pop();
            if(!st.count(f)) {
                level.push_back(f);
                st.insert(f);
                int curY = f.first, curX = f.second;
                if(move == '^') {
                    if(inBounds(grid, curY - 1, curX) && ((grid[curY-1][curX] == '[') || (grid[curY-1][curX] == ']'))) {
                        q.push({curY - 1, curX});
                        if(grid[curY-1][curX] == '[') {
                            q.push({curY - 1, curX + 1});
                        }
                        else if(grid[curY-1][curX] == ']') {
                            q.push({curY - 1, curX - 1});
                        }
                    }
                }
                else if(move == 'v') {
                    if(inBounds(grid, curY + 1, curX) && ((grid[curY+1][curX] == '[') || (grid[curY+1][curX] == ']'))) {
                        q.push({curY + 1, curX});
                        if(grid[curY+1][curX] == '[') {
                            q.push({curY + 1, curX + 1});
                        }
                        else if(grid[curY+1][curX] == ']') {
                            q.push({curY + 1, curX - 1});
                        }
                    }
                }
                else if(move == '<') {
                    if(inBounds(grid, curY, curX - 1) && grid[curY][curX-1] == ']') {
                        q.push({curY, curX - 2});
                        q.push({curY, curX - 1});
                    }
                }
                else {
                    if(inBounds(grid, curY, curX + 1) && grid[curY][curX+1] == '[') {
                        q.push({curY, curX + 2});
                        q.push({curY, curX + 1});
                    }
                }
            }
        }
        if(level.size() > 0) {
            neighbors.push_back(level);
        }
    }
    // Try moving each level of neighbors starting from the back.
    // On failure to move, don't move anything at all.
    int numLevels = neighbors.size();
    vector<vector<char>> gridCopy = grid;
    bool ok = true;

    // // Print neighbors
    // for(int i=0;i<numLevels;i++) {
    //     vector<pair<int, int>> level = neighbors[i];
    //     cout << "Level: " << i << endl;
    //     for(pair<int, int> p : level) {
    //         cout << p.first << ' ' << p.second << endl;
    //     }
    //     cout << endl;
    // }

    for(int i=numLevels-1;i>=0;i--) {
        vector<pair<int, int>> level = neighbors[i];
        for(pair<int, int> p : level) {
            int nextY = p.first, nextX = p.second;
            if(move == '^') {
                nextY--;
            }
            else if(move == 'v') {
                nextY++;
            }
            else if(move == '<') {
                nextX--;
            }
            else {
                nextX++;
            }
            if(inBounds(gridCopy, nextY, nextX)) {
                gridCopy[nextY][nextX] = gridCopy[p.first][p.second];
                gridCopy[p.first][p.second] = '.';
            }
            else {
                ok = false;
                break;
            }
        }
        if(!ok) {
            break;
        }
    }
    if(ok) {
        grid = gridCopy;
    }
}

void simulateLargerMoves(vector<vector<char>> &grid, string moves) {
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<moves.size();i++) {
        char c = moves[i];
        //cout << "Move " << i << ": " << c << endl;
        pair<int, int> pos = getStartingPos(grid);
        move(grid, c, pos);
        //printGrid(grid);
    }
}

int getGpsCoordSum(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'O') {
                res += (i * 100 + j);
            }
        }
    }
    return res;
}

int getLargerGpsCoordSum(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '[') {
                res += (i * 100 + j);
            }
        }
    }
    return res;
}

void part1(vector<vector<char>> grid, string moves) {
    simulateMoves(grid, moves);
    int res = getGpsCoordSum(grid);
    cout << res << endl;
}

void part2(vector<vector<char>> grid, string moves) {
    simulateLargerMoves(grid, moves);
    printGrid(grid);
    int res = getLargerGpsCoordSum(grid);
    cout << res << endl;
}

int main() {
    IOS
    string s;
    string moves;
    vector<vector<char>> grid, largerGrid;
    while(getline(cin, s)) {
        if(s.empty()) {
            while(getline(cin, s)) {
                moves += s;
            }
        }
        else {
            string largerS;
            vector<char> row(s.begin(), s.end());
            for(char c : row) {
                if(c == '#') {
                    largerS += "##";
                }
                else if(c == 'O') {
                    largerS += "[]";
                }
                else if(c == '.') {
                    largerS += "..";
                }
                else if(c == '@') {
                    largerS += "@.";
                }
            }
            vector<char> largerRow(largerS.begin(), largerS.end());
            grid.push_back(row);
            largerGrid.push_back(largerRow);
        }
    }
    //part1(grid, moves);
    part2(largerGrid, moves);
    return 0;
}
