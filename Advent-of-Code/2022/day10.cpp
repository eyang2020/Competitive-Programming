#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> reg(1000); // let reg[i] denote the value of the register during cycle i

void part1(vector<pair<string, int>> lines) {
	reg[1] = 1;
	int cycle = 1;
	for(auto line : lines) {
		string command = line.first;
		int x = line.second;
		if(command == "noop") {
			reg[cycle + 1] = reg[cycle];
			cycle++;
		}
		else if(command == "addx") {
			reg[cycle + 1] = reg[cycle];
			reg[cycle + 2] = reg[cycle] + x;
			cycle += 2;
		}
	}
	vector<int> indicies = {20, 60, 100, 140, 180, 220};
	int res = 0;
	for(auto i : indicies) {
		res += i * reg[i];
	}
	cout << res << endl;
}

void part2(vector<pair<string, int>> lines) {
	vector<string> crt(6);
	for(int i=0;i<6;i++) {
		string s;
		for(int j=1;j<=40;j++) {
			int cycle = i * 40 + j;
			if(abs((cycle % 40) - reg[cycle + 1]) < 2) {
				s += '#';
			}
			else {
				s += '.';
			}
		}
		crt[i] = s;
	}
	for(auto s : crt) {
		cout << s << endl;
	}
}

int main() {
	vector<pair<string, int>> lines;
	string s;
	while(getline(cin, s)) {
		int pos = s.find(" ");
		if(pos != std::string::npos) {
			string token = s.substr(0, pos);
			s.erase(0, pos + 1);
			lines.push_back({token, stoi(s)});
		}	
		else {
			lines.push_back({s, 0});
		}
	}
	part1(lines);
	part2(lines);
}
