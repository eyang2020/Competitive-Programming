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

void part1() {

}

void part2() {

}

int main() {
	IOS
	part1();
	part2();
}
