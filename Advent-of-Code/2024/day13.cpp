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

struct Machine {
    pair<ll, ll> buttonA;
    pair<ll, ll> buttonB;
    pair<ll, ll> prize;
};

ll getMinTokens(Machine machine) {
    ll res = -1;
    for(int i=0;i<=100;i++) {
        pair<ll, ll> cur = {machine.buttonA.first * i, machine.buttonA.second * i};
        pair<ll, ll> diff = {machine.prize.first - cur.first, machine.prize.second - cur.second};
        if(diff.first % machine.buttonB.first == 0 && diff.second % machine.buttonB.second == 0 && (diff.first / machine.buttonB.first) == (diff.second / machine.buttonB.second)) {
            if(res == -1) {
                res = i * 3 + diff.first / machine.buttonB.first;
            }
            else {
                res = min(res, i * 3 + diff.first / machine.buttonB.first);
            }
        }
    }
    return ((res == -1) ? 0 : res);
}

ll getA(Machine machine) {
    ll tX = machine.prize.first, tY = machine.prize.second;
    ll aX = machine.buttonA.first, aY = machine.buttonA.second;
    ll bX = machine.buttonB.first, bY = machine.buttonB.second;
    // (machines[i].buttonB.second * machines[i].prize.first - machines[i].buttonB.first * machines[i].prize.second) / (machines[i].buttonA.first * machines[i].buttonB.second - machines[i].buttonB.first * machines[i].buttonA.second);
    return (bY * tX - bX * tY) / (aX * bY - bX * aY);
}

ll getB(Machine machine) {
    ll tX = machine.prize.first, tY = machine.prize.second;
    ll aX = machine.buttonA.first, aY = machine.buttonA.second;
    ll bX = machine.buttonB.first, bY = machine.buttonB.second;
    // (machines[i].buttonA.first * machines[i].prize.second - machines[i].buttonA.second * machines[i].prize.first) / (machines[i].buttonA.first * machines[i].buttonB.second - machines[i].buttonB.first * machines[i].buttonA.second);
    return (aX * tY - aY * tX) / (aX * bY - bX * aY);
}

void part1(vector<Machine> machines) {
    int n = machines.size();
    // ll res = 0;
    // for(int i=0;i<n;i++) {
    //     res += getMinTokens(machines[i]);
    // }
    // cout << res << endl;
    ll res = 0;
    for(int i=0;i<n;i++) {
        ll tX = machines[i].prize.first, tY = machines[i].prize.second;
        ll aX = machines[i].buttonA.first, aY = machines[i].buttonA.second;
        ll bX = machines[i].buttonB.first, bY = machines[i].buttonB.second;
        ll a = getA(machines[i]);
        ll b = getB(machines[i]);
        //cout << a << ' ' << b << endl;
        if((a * aX + b * bX == tX) && ((a * aY + b * bY == tY))) {
            res += a * 3 + b;
        }
    }
    cout << res << endl;
}

void part2(vector<Machine> machines) {
    int n = machines.size();
    ll add = 10000000000000;
    for(int i=0;i<n;i++) {
        //cout << machines[i].prize.first << ' ' << machines[i].prize.second << endl;
        Machine machine = {machines[i].buttonA, machines[i].buttonB, {machines[i].prize.first + add, machines[i].prize.second + add}};
        machines[i] = machine;
        //cout << machines[i].prize.first << ' ' << machines[i].prize.second << endl;
    }
    ll res = 0;
    for(int i=0;i<n;i++) {
        ll tX = machines[i].prize.first, tY = machines[i].prize.second;
        ll aX = machines[i].buttonA.first, aY = machines[i].buttonA.second;
        ll bX = machines[i].buttonB.first, bY = machines[i].buttonB.second;
        ll a = getA(machines[i]);
        ll b = getB(machines[i]);
        //cout << a << ' ' << b << endl;
        if((a * aX + b * bX == tX) && ((a * aY + b * bY == tY))) {
            res += a * 3 + b;
        }
    }
    cout << res << endl;
}

int main() {
    IOS
    string buttonA;
    vector<Machine> machines;
    while(getline(cin, buttonA)) {
        string buttonB, prize;
        getline(cin, buttonB);
        getline(cin, prize);
        vector<string> vA = tokenize(buttonA, ": ");
        vector<string> vB = tokenize(buttonB, ": ");
        vector<string> vPrize = tokenize(prize, ": ");
        vA = tokenize(vA[1], ", ");
        ll aX = stol(tokenize(vA[0], "+")[1]), aY = stol(tokenize(vA[1], "+")[1]);
        vB = tokenize(vB[1], ", ");
        ll bX = stol(tokenize(vB[0], "+")[1]), bY = stol(tokenize(vB[1], "+")[1]);
        vPrize = tokenize(vPrize[1], ", ");
        ll prizeX = stol(tokenize(vPrize[0], "=")[1]), prizeY = stol(tokenize(vPrize[1], "=")[1]);
        Machine machine = {{aX, aY}, {bX, bY}, {prizeX, prizeY}};
        machines.push_back(machine);
        getline(cin, buttonA);
    }
    //part1(machines);
    part2(machines);
    return 0;
}
