#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0}; 
const int dx_diag[4] = {-1, -1, 1, 1};
const int dy_diag[4] = {-1, 1, -1, 1};

bool is_adjacent(pair<int, int> p1, pair<int, int> p2) {
    return !(abs(p1.first - p2.first) > 1 || abs(p1.second - p2.second) > 1);
}

pair<int, int> get_next_move(bool use_diag, pair<int, int> p1, pair<int, int> p2) {
    pair<int, int> res = p1;
    if(use_diag) {
        for(int i=0;i<4;i++) {
            pair<int, int> temp = p2;
            temp.first += dx_diag[i];
            temp.second += dy_diag[i];
            if(is_adjacent(p1, temp)) {
                res = temp;
                break;
            }
        }
    }
    else {
        for(int i=0;i<4;i++) {
            pair<int, int> temp = p2;
            temp.first += dx[i];
            temp.second += dy[i];
            if(is_adjacent(p1, temp)) {
                res = temp;
                break;
            }
        }
    }
    return res;
}

void part1(vector<pair<char, int>> lines) {
    set<pair<int, int>> vis;
    pair<int, int> h_coords = {0, 0};
    pair<int, int> t_coords = {0, 0};
    vis.insert(t_coords);
    for(auto p : lines) {
        char c = p.first;
        int x = p.second;
        for(int i=0;i<x;i++) {
            // move H
            if(c == 'U') {
                h_coords.first++;
            }
            else if(c == 'D') {
                h_coords.first--;
            }
            else if(c == 'L') {
                h_coords.second--;
            } 
            else if(c == 'R') {
                h_coords.second++;
            }
            // move T to remain adjacent to H
            if(!is_adjacent(h_coords, t_coords)) {
                bool use_diag = h_coords.first != t_coords.first && h_coords.second != t_coords.second;
                t_coords = get_next_move(use_diag, h_coords, t_coords);
            }
            // track coordinates of T
            vis.insert(t_coords);
        }
    }
    cout << vis.size() << endl;
}

void part2(vector<pair<char, int>> lines) {
    set<pair<int, int>> vis;
    // let coords[0] be the head and coords[9] be the tail
    vector<pair<int, int>> coords(10);
    for(int i=0;i<10;i++) {
        coords[i] = {0, 0};
    }
    vis.insert(coords[9]);
    for(auto p : lines) {
        char c = p.first;
        int x = p.second;
        for(int i=0;i<x;i++) {
            // move H
            if(c == 'U') {
                coords[0].first++;
            }
            else if(c == 'D') {
                coords[0].first--;
            }
            else if(c == 'L') {
                coords[0].second--;
            } 
            else if(c == 'R') {
                coords[0].second++;
            }
            // for each knot, move each previous knot
            for(int j=0;j<9;j++) {
                if(!is_adjacent(coords[j], coords[j+1])) {
                    bool use_diag = coords[j].first != coords[j+1].first && coords[j].second != coords[j+1].second;
                    coords[j+1] = get_next_move(use_diag, coords[j], coords[j+1]);
                }
            }
            // track coordinates of coords[9]
            vis.insert(coords[9]);
        }
    }
    cout << vis.size() << endl;
}

int main() {
    vector<pair<char, int>> lines;
    string s;
    while(getline(cin, s)) {
        int pos = s.find(" ");
        string token = s.substr(0, pos);
        s.erase(0, pos + 1);
        lines.push_back(make_pair(token[0], stoi(s)));
    }
	part1(lines);
	part2(lines);
}
