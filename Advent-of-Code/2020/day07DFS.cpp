#include <bits/stdc++.h> 
#include <regex>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = (ll)1e18;
const int N = 3e5 + 5;
const ll MOD = 1e9+7;

int parent[N];
 
int gcd(int a, int b) { 
    if (a == 0) 
        return b;  
    return gcd(b%a, a);  
} 
   
int lcm(int a, int b) {  
    return (a*b)/gcd(a,b);  
} 
 
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
 
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int xPar = find(x), yPar = find(y);
    if(xPar != yPar) parent[xPar] = yPar;
}
 
ll nCr(ll n, ll r) {
    ll res = 1;
    for(ll i=1;i<=r;i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}
 
int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int v;
    cin >> v;
    return v;
}

int msbPos(int n) {
    if(n == 0) return 0;
    int msbPos = 0;
    n /= 2;
    while(n != 0) {
        n /= 2;
        msbPos++;
    }
    return msbPos;
}

map<string, vector<pair<string, int>>> mp;
set<string> bags;
int res = 0;

bool dfs(string x) {
    if(x == "shiny gold") {
        res++;
        return true;
    }
    vector<pair<string, int>> b = mp[x];
    for(auto next : b) {
        if(dfs(next.first)) {
            return true;
        }
    }
    return false;
}

void part1() {
    string s;
    regex rx1("(\\S+ \\S+) bags contain (.+)\\.");
    regex rx2("(\\d+) (\\S+ \\S+) bag[s]?[, ]?");
    smatch match1, match2;
    while(getline(cin, s)) {
        if(regex_search(s, match1, rx1)) {
            string parent = match1[1];
            bags.insert(parent);
            string contentsList = match1[2];
            while(regex_search(contentsList, match2, rx2)) {
                int amount = atoi(string(match2[1]).data());
                string name = match2[2];
                mp[parent].push_back({name, amount});
                bags.insert(name);
                contentsList.erase(0, string(match2[0]).size());
            }
        }
    }
    for(auto x : bags) {
        if(x == "shiny gold") continue;
        dfs(x);
    }
    cout << res << endl;
    return;
} 

void part2() {
    string s;
    regex rx1("(\\S+ \\S+) bags contain (.+)\\.");
    regex rx2("(\\d+) (\\S+ \\S+) bag[s]?[, ]?");
    smatch match1, match2;
    while(getline(cin, s)) {
        if(regex_search(s, match1, rx1)) {
            string parent = match1[1];
            bags.insert(parent);
            string contentsList = match1[2];
            while(regex_search(contentsList, match2, rx2)) {
                int amount = atoi(string(match2[1]).data());
                string name = match2[2];
                mp[parent].push_back({name, amount});
                bags.insert(name);
                contentsList.erase(0, string(match2[0]).size());
            }
        }
    }
    int res = 0;
    queue<pair<string, int>> q;
    q.push({"shiny gold", 1});
    while(q.size() > 0) {
        pair<string, int> f = q.front();
        res += f.second;
        for(auto next : mp[f.first]) {
            q.push({next.first, next.second * f.second});
        }
        q.pop();
    }
    cout << res - 1 << endl;
    return;
}

int main()
{
    IOS
    part1();
    return 0; 
}
