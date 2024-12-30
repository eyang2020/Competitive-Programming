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

const int HEIGHT = 103, WIDTH = 101, NUM_SIMULATIONS = 10000;

struct Robot {
    pair<int, int> pos;
    pair<int, int> vel;
};

void simulate(vector<Robot> &robots, vector<vector<int>> &grid) {
    int n = robots.size();
    for(int i=0;i<n;i++) {
        Robot r = robots[i];
        pair<int, int> nextPos = {((r.pos.first + r.vel.first) + WIDTH) % WIDTH, ((r.pos.second + r.vel.second) + HEIGHT) % HEIGHT};
        grid[r.pos.second][r.pos.first]--;
        grid[nextPos.second][nextPos.first]++;
        robots[i] = {nextPos, r.vel};
    }
}

int getSafetyFactor(vector<vector<int>> grid) {
    int MID_HEIGHT = HEIGHT / 2, MID_WIDTH = WIDTH / 2;
    int cntQ1 = 0, cntQ2 = 0, cntQ3 = 0, cntQ4 = 0;
    // Q1
    for(int i=0;i<MID_HEIGHT;i++) {
        for(int j=0;j<MID_WIDTH;j++) {
            cntQ1 += grid[i][j];
        }
    }
    // Q2
    for(int i=0;i<MID_HEIGHT;i++) {
        for(int j=MID_WIDTH+1;j<WIDTH;j++) {
            cntQ2 += grid[i][j];
        }
    }
    // Q3
    for(int i=MID_HEIGHT+1;i<HEIGHT;i++) {
        for(int j=0;j<MID_WIDTH;j++) {
            cntQ3 += grid[i][j];
        }
    }
    // Q4
    for(int i=MID_HEIGHT+1;i<HEIGHT;i++) {
        for(int j=MID_WIDTH+1;j<WIDTH;j++) {
            cntQ4 += grid[i][j];
        }
    }
    int res = cntQ1 * cntQ2 * cntQ3 * cntQ4;
    return res;
}

void part1(vector<Robot> robots) {
    int n = robots.size();
    vector<vector<int>> grid(HEIGHT, vector<int>(WIDTH, 0));
    for(Robot r : robots) {
        grid[r.pos.second][r.pos.first]++;
    }
    for(int i=0;i<NUM_SIMULATIONS;i++) {
        simulate(robots, grid);
    }
    int res = getSafetyFactor(grid);
    cout << res << endl;
}

void part2(vector<Robot> robots) {
    int n = robots.size();
    vector<vector<int>> grid(HEIGHT, vector<int>(WIDTH, 0));
    for(Robot r : robots) {
        grid[r.pos.second][r.pos.first]++;
    }
    for(int i=0;i<NUM_SIMULATIONS;i++) {
        simulate(robots, grid);
        bool ok = true;
        for(int i=0;i<HEIGHT;i++) {
            for(int j=0;j<WIDTH;j++) {
                if(grid[i][j] > 1) {
                    // This assumption that the robots that form the tree do not overlap is based on literally nothing
                    // Actual terrible problem
                    ok = false;
                }
            }
        }
        if(ok) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    IOS
    string s;
    vector<Robot> robots;
    while(getline(cin, s)) {
        vector<string> v1 = tokenize(s, " ");
        vector<string> v2 = tokenize(tokenize(v1[0], "=")[1], ",");
        vector<string> v3 = tokenize(tokenize(v1[1], "=")[1], ",");
        Robot robot = {{stoi(v2[0]), stoi(v2[1])}, {stoi(v3[0]), stoi(v3[1])}};
        robots.push_back(robot);
    }
    //part1(robots);
    part2(robots);
    return 0;
}
