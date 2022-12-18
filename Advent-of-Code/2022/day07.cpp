#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int TOTAL_DISK_SPACE = 70000000;
const int NEEDED_DISK_SPACE = 30000000;
const int INF = 1e9;

vector<string> path;
map<string, int> path_to_size_map;

string path_vector_to_path_str(vector<string> path, int idx) {
	string res;
	for(int i=0;i<=idx;i++) {
		res += path[i] + '/';
	}
	return res;
}

void part1() {
	int res = 0;
	for(auto p : path_to_size_map) {
		if(p.second <= 100000) {
			res += p.second;
		}
	}
	cout << res << endl;
}

void part2() {
	int res = INF;
	for(auto p : path_to_size_map) {
		if(TOTAL_DISK_SPACE - path_to_size_map["//"] + p.second >= NEEDED_DISK_SPACE) {
			res = min(res, p.second);
		}
	}
	cout << res << endl;
}

int main() {
	string s;
	vector<vector<string>> lines;
	while(getline(cin, s)) {
		vector<string> cur;
		int pos = 0;
		string token;
		while((pos = s.find(" ")) != std::string::npos) {
			token = s.substr(0, pos);
			cur.push_back(token);
			s.erase(0, pos + 1);
		}
		if(s.length() > 0) {
			cur.push_back(s);
		}
		lines.push_back(cur);
	}
	for(auto line : lines) {
		if(line[0] == "$") {
			if(line[1] == "cd") {
				if(line[2] == "..") {
					path.pop_back();	
				}
				else {
					path.push_back(line[2]);
				}
			}
		}
		else if(line[0] != "dir") {
			for(int i=0;i<path.size();i++) {
				path_to_size_map[path_vector_to_path_str(path, i)] += stoi(line[0]);
			}
		}
	}
	part1();
	part2();
}
