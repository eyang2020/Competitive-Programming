#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void part1(vector<deque<char>> stacks, vector<tuple<int, int, int>> moves) {
	for(auto tup : moves) {
		int amount = get<0>(tup), from = get<1>(tup) - 1, to = get<2>(tup) - 1;
		while(amount--) {
			stacks[to].push_back(stacks[from].back());
			stacks[from].pop_back();
		}
	}
	for(auto stack : stacks) {
		cout << stack.back();
	}
	cout << endl;
}

void part2(vector<deque<char>> stacks, vector<tuple<int, int, int>> moves) {
	for(auto tup : moves) {
		int amount = get<0>(tup), from = get<1>(tup) - 1, to = get<2>(tup) - 1;
		vector<char> temp;
		while(amount--) {
			temp.push_back(stacks[from].back());
			stacks[from].pop_back();
		}
		for(int i=temp.size()-1;i>=0;i--) {
			stacks[to].push_back(temp[i]);
		}
	}
	for(auto stack : stacks) {
		cout << stack.back();
	}
	cout << endl;
}

int main() {
    string s;
	vector<deque<char>> stacks;
	while(getline(cin, s)) {
		int n = s.length();
		if(n == 0 || s[1] == '1') {
			break;
		}
		for(int i=1,j=0;i<n;i+=4,j++) {
			if(j >= stacks.size()) {
				stacks.push_back({});
			}
			if(s[i] != ' ') {
				stacks[j].push_front(s[i]);
			}
		}
	}
	getline(cin, s);
	vector<tuple<int, int, int>> moves;
	while(getline(cin, s)) {
		vector<string> tokens;
		int pos = 0;
		string token;
		while((pos = s.find(" ")) != std::string::npos) {
			token = s.substr(0, pos);
			tokens.push_back(token);
			s.erase(0, pos + 1);
		}
		tokens.push_back(s);
		tuple<int, int, int> tup(stoi(tokens[1]), stoi(tokens[3]), stoi(tokens[5]));
		moves.push_back(tup);
	}
	part1(stacks, moves);
	part2(stacks, moves);
}