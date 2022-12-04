#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void part1(vector<vector<int>> v) {
    int res = 0;
    for(auto x : v) {
        if((x[0] <= x[2] && x[3] <= x[1]) || (x[2] <= x[0] && x[1] <= x[3])) {
            res++;
        }
    }
    cout << res << endl;
}

void part2(vector<vector<int>> v) {
    int res = 0;
    for(auto x : v) {
        if((x[0] <= x[2] && x[2] <= x[1]) || (x[2] <= x[1] && x[1] <= x[3]) || (x[2] <= x[0] && x[0] <= x[3]) || (x[0] <= x[3] && x[3]<= x[1])) {
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    string s;
    vector<vector<int>> v;
    while(getline(cin, s)) {
        vector<int> cur;
        int pos = s.find(",");
        string a = s.substr(0, pos);
        string b = s.substr(pos + 1);
        pos = a.find("-");
        cur.push_back(stoi(a.substr(0, pos)));
        cur.push_back(stoi(a.substr(pos + 1)));
        pos = b.find("-");
        cur.push_back(stoi(b.substr(0, pos)));
        cur.push_back(stoi(b.substr(pos + 1)));
        v.push_back(cur);
    }
	part1(v);
	part2(v);
}
