#include <bits/stdc++.h> 
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

void part1() {
    string s;
    int res = 0;
    vector<string> a;
    while(getline(cin, s)) {
        //if(s.empty()) cout << "empty" << endl;
        //else cout << s << endl;
        if(s.empty()) {
            //cout << "pog" << endl;
            if(a.size() == 8 || (a.size() == 7 && count(a.begin(), a.end(), "cid") == 0))  {
                res++;
            }
            a.clear();
        }
        else {
            string cur = "";
            for(int i=0;i<s.length();i++) {
                if(s[i] == ' ') {
                    a.push_back(cur.substr(0, cur.find(":")));
                    cur = "";
                }
                else {
                    cur += s[i];
                }
            }
            if(cur.size() > 0) a.push_back(cur.substr(0, cur.find(":")));
        }
    }
    if(!s.empty()) {
        //cout << "pog" << endl;
        if(a.size() == 8 || (a.size() == 7 && count(a.begin(), a.end(), "cid") == 0))  {
            res++;
        }
        a.clear();
    }
    cout << res << endl;
    return;
}

bool ok(map<string, string> mp) {
    /*for(auto p : mp) {
        cout << p.first << ':' << p.second << endl;
    }
    cout << endl;*/
    if(mp.size() >= 7) {
        if(mp.find("byr") == mp.end()) return false;
        int byr = stoi(mp["byr"]);
        //cout << byr << endl;
        if(!(byr >= 1920 && byr <= 2002)) return false;

        if(mp.find("iyr") == mp.end()) return false;
        int iyr = stoi(mp["iyr"]);
        if(!(iyr >= 2010 && iyr <= 2020)) return false;

        if(mp.find("eyr") == mp.end()) return false;
        int eyr = stoi(mp["eyr"]);
        if(!(eyr >= 2020 && eyr <= 2030)) return false;

        if(mp.find("hgt") == mp.end()) return false;
        string hgt = mp["hgt"];
        //cout << hgt << endl;
        if(hgt.find("cm") != string::npos) {
            int h = stoi(hgt.substr(0, hgt.find("c")));
            //cout << "cm " << h << endl;
            if(!(h >= 150 &&  h <= 193)) return false;
        }
        else if(hgt.find("in") != string::npos) {
            int h = stoi(hgt.substr(0, hgt.find("i")));
            //cout << "in " << h << endl;
            if(!(h >= 59 && h <= 76)) return false;
        }
        else return false;

        //cout << "pog" << endl;

        if(mp.find("hcl") == mp.end()) return false;
        string hcl = mp["hcl"];
        if(hcl.length() != 7) return false;
        //cout << hcl << endl;
        if(hcl[0] != '#') return false;
        for(int i=1;i<hcl.length();i++) {
            char c = hcl[i];
            if(isdigit(c)) {
                if(!(c >= '0' && c <= '9')) return false;
            }
            else {
                if(!(c >= 'a' && c <= 'f')) return false;
            }
        }
        //cout << "we back" << endl;

        if(mp.find("ecl") == mp.end()) return false;
        string ecl = mp["ecl"];
        //cout << ecl << endl;
        vector<string> temp = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
        if(count(temp.begin(), temp.end(), ecl) == 0) return false;
        //cout << "PAGCHOMP" << endl;

        if(mp.find("pid") == mp.end()) return false;
        string pid = mp["pid"];
        if(pid.length() != 9) return false;
        for(int i=0;i<9;i++) {
            if(!isdigit(pid[i])) return false;
        }
    }
    else return false;
    return true;
}

void part2() {
    string s;
    int res = 0;
    map<string, string> mp;
    while(getline(cin, s)) {
        if(s.empty()) {
            if(ok(mp)) {
                res++;
            }
            mp.clear();
        }
        else {
            string cur = "";
            for(int i=0;i<s.length();i++) {
                if(s[i] == ' ') {
                    int idx = cur.find(":");
                    mp[cur.substr(0, idx)] = cur.substr(idx + 1);
                    cur = "";
                }
                else {
                    cur += s[i];
                }
            }
            if(cur.size() > 0) {
                int idx = cur.find(":");
                mp[cur.substr(0, idx)] = cur.substr(idx + 1);
            }
        }
    }
    if(!s.empty()) {
        if(ok(mp)) {
            res++;
        }
    }
    cout << res << endl;
    return;
}

int main()
{
    IOS
    part2();
    return 0; 
}
