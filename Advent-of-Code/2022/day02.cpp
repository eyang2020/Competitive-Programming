#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

map<char, int> score_map;
map<char, map<char, int>> game_map;
map<char, map<char, char>> choice_map;

void part1(vector<vector<char>> moves) {
    int res = 0;
    for(auto v : moves) { 
        res += score_map[v[1]] + game_map[v[0]][v[1]];
    }
    cout << res << endl;
}

void part2(vector<vector<char>> moves) {
    int res = 0;
    for(auto v : moves) {
        char move = choice_map[v[0]][v[1]];
        res += score_map[move] + game_map[v[0]][move];
    }
    cout << res << endl;
}

int main() {
    score_map = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    game_map = {
        {'A', {{'X', 3}, {'Y', 6}, {'Z', 0}}},
        {'B', {{'X', 0}, {'Y', 3}, {'Z', 6}}},
        {'C', {{'X', 6}, {'Y', 0}, {'Z', 3}}}
    };
    choice_map = {
        {'A', {{'X', 'Z'}, {'Y', 'X'}, {'Z', 'Y'}}},
        {'B', {{'X', 'X'}, {'Y', 'Y'}, {'Z', 'Z'}}},
        {'C', {{'X', 'Y'}, {'Y', 'Z'}, {'Z', 'X'}}}
    };
    string s;
    vector<vector<char>> moves;
    while(getline(cin, s)) {
        vector<char> cur;
        int pos = 0;
        string token;
        while((pos = s.find(" ")) != std::string::npos) {
            token = s.substr(0, pos);
            cur.push_back(token[0]);
            s.erase(0, pos + 1);
        }
        cur.push_back(s[0]);
        moves.push_back(cur);
    }
	part1(moves);
	part2(moves);
}
