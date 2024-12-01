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

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

struct Crucible {
    int cost;
    int numMoves;
    Direction dir;
    pair<int, int> pos;
};

struct CrucibleComparator {
    bool operator() (Crucible c1, Crucible c2) const {
        return c1.cost > c2.cost;
    }
};

bool areOppositeDirections(Direction d1, Direction d2) {
    return (d1 == Direction::NORTH && d2 == Direction::SOUTH)
        || (d1 == Direction::SOUTH && d2 == Direction::NORTH)
        || (d1 == Direction::EAST && d2 == Direction::WEST)
        || (d1 == Direction::WEST && d2 == Direction::EAST);
}

pair<int, int> getNextPos(Direction nextDir, pair<int, int> curPos) {
    pair<int, int> nextPos = curPos;
    if(nextDir == Direction::NORTH) {
        nextPos = {curPos.first - 1, curPos.second};
    }
    else if(nextDir == Direction::SOUTH) {
        nextPos = {curPos.first + 1, curPos.second};
    }
    else if(nextDir == Direction::EAST) {
        nextPos = {curPos.first, curPos.second + 1};
    }
    else {
        nextPos = {curPos.first, curPos.second - 1};
    }
    return nextPos;
}

int getNextNumMoves(Direction nextDir, Direction curDir, int curNumMoves) {
    return ((nextDir == curDir) ? (curNumMoves + 1) : 1);
}

bool inBounds(int n, int m, pair<int, int> pos) {
    int y = pos.first, x = pos.second;
    return (0 <= y && y < n && 0 <= x && x < m);
}

string hashCrucible(Crucible c) {
    string input = to_string(c.dir * 100 + 1) + to_string(c.pos.first * 100 + 2) + to_string(c.pos.second * 100 + 3) + to_string(c.numMoves * 100 + 4);
    return input;
}

void part1(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
    Crucible east = {grid[0][1], 1, Direction::EAST, {0, 1}};
    Crucible south = {grid[1][0], 1, Direction::SOUTH, {1, 0}};
    priority_queue<Crucible, vector<Crucible>, CrucibleComparator> pq;
    pq.push(east);
    pq.push(south);
    set<string> vis;
    vis.insert(hashCrucible(east));
    vis.insert(hashCrucible(south));
    while(!pq.empty()) {
        Crucible c = pq.top();
        if(c.pos.first == n - 1 && c.pos.second == m - 1) {
            cout << c.cost << endl;
            return;
        }
        pq.pop();
        vector<Crucible> adj;
        vector<Direction> directions = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};
        for(Direction nextDir : directions) {
            if(areOppositeDirections(c.dir, nextDir) || (c.dir == nextDir && c.numMoves >= 3)) {
                continue;
            }
            pair<int, int> nextPos = getNextPos(nextDir, c.pos);
            int nextNumMoves = getNextNumMoves(nextDir, c.dir, c.numMoves);
            if(inBounds(n, m, nextPos)) {
                int nextCost = c.cost + grid[nextPos.first][nextPos.second];
                Crucible next = {nextCost, nextNumMoves, nextDir, nextPos};
                adj.push_back(next);
            }
        }
        for(Crucible next : adj) {
            string hashedCrucible = hashCrucible(next);
            if(!vis.count(hashedCrucible)) {
                vis.insert(hashedCrucible);
                pq.push(next);
            }
        }
    }
}

void part2(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
    Crucible east = {grid[0][1], 1, Direction::EAST, {0, 1}};
    Crucible south = {grid[1][0], 1, Direction::SOUTH, {1, 0}};
    priority_queue<Crucible, vector<Crucible>, CrucibleComparator> pq;
    pq.push(east);
    pq.push(south);
    set<string> vis;
    vis.insert(hashCrucible(east));
    vis.insert(hashCrucible(south));
    while(!pq.empty()) {
        Crucible c = pq.top();
        if((c.pos.first == n - 1 && c.pos.second == m - 1) && (c.numMoves >= 4)) {
            cout << c.cost << endl;
            return;
        }
        pq.pop();
        vector<Crucible> adj;
        vector<Direction> directions = {Direction::NORTH, Direction::SOUTH, Direction::EAST, Direction::WEST};
        for(Direction nextDir : directions) {
            if(areOppositeDirections(c.dir, nextDir)) {
                continue;
            }
            if(c.dir != nextDir && c.numMoves < 4) {
                continue;
            }
            if(c.dir == nextDir && c.numMoves >= 10) {
                continue;
            }
            pair<int, int> nextPos = getNextPos(nextDir, c.pos);
            int nextNumMoves = getNextNumMoves(nextDir, c.dir, c.numMoves);
            if(inBounds(n, m, nextPos)) {
                int nextCost = c.cost + grid[nextPos.first][nextPos.second];
                Crucible next = {nextCost, nextNumMoves, nextDir, nextPos};
                adj.push_back(next);
            }
        }
        for(Crucible next : adj) {
            string hashedCrucible = hashCrucible(next);
            if(!vis.count(hashedCrucible)) {
                vis.insert(hashedCrucible);
                pq.push(next);
            }
        }
    }
}

int main() {
    IOS
    string s;
    vector<vector<int>> grid;
    while(getline(cin, s)) {
        vector<int> row;
        for(char c : s) {
            row.push_back(c - '0');
        }
        grid.push_back(row);
    }
    part1(grid);
    part2(grid);
    return 0;
}
