#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<string> split(string s, string delim) {
    int pos;
    string token;
    vector<string> tokens;
    while((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delim.length());
        tokens.push_back(token);
    }
    if (s.length() > 0) {
        tokens.push_back(s);
    }
    return tokens;
}

void part1(vector<map<string, int>> a) {
    int n = a.size(), res = 0, R = 12, G = 13, B = 14;
    for(int i=0;i<n;i++) {
        map<string, int> mp = a[i];
        if (mp["red"] <= R && mp["green"] <= G && mp["blue"] <= B) {
            res += i + 1;
        }
    }
    cout << res << endl;
}

void part2(vector<map<string, int>> a) {
    int n = a.size(), res = 0;
    for(int i=0;i<n;i++) {
        map<string, int> mp = a[i];
        res += mp["red"] * mp["green"] * mp["blue"];
    }
    cout << res << endl;
}

int main() {
	IOS
    string s;
    vector<map<string, int>> a;
    while(getline(cin, s)) {
        map<string, int> mp;
        s.erase(0, s.find(": ") + 2);
        vector<string> game = split(s, "; ");
        for(string turn : game) {
            vector<string> grabs = split(turn, ", ");
            for(string grab : grabs) {
                vector<string> pair = split(grab, " ");
                mp[pair[1]] = max(mp[pair[1]], stoi(pair[0]));
            }
        }
        a.push_back(mp);
    }
	part1(a);
	part2(a);
}
