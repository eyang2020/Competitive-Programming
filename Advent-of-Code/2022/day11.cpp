#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Monkey {
	int id, throw_to_true, throw_to_false;
	ll divisible_by;
	vector<string> op;
	queue<ll> items;
};

ll update_item(ll old, vector<string> op) {
	ll res = old, x = old, y = old;
	if(op[0] != "old") {
		x = stol(op[0]);
	}
	if(op[2] != "old") {
		y = stol(op[2]);
	}
	if(op[1] == "+") {
		res = x + y;
	}
	else if(op[1] == "*") {
		res = x * y;
	}
	return res;
}

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

void part1(vector<Monkey> monkeys) {
	map<ll, ll> id_to_num_inspections_map;
	for(int round=1;round<=20;round++) {
		for(Monkey &m : monkeys) {
			id_to_num_inspections_map[m.id] += m.items.size();
			while(!m.items.empty()) {
				ll item = m.items.front();
				m.items.pop();
				item = update_item(item, m.op);
				item /= 3;
				if(item % m.divisible_by == 0) {
					monkeys[m.throw_to_true].items.push(item);
				}
				else {
					monkeys[m.throw_to_false].items.push(item);
				}
			}
		}
	}
	ll mx1 = 0, mx2 = 0;
	for(auto p : id_to_num_inspections_map) {
		if(p.second > mx1) {
			mx2 = mx1;
			mx1 = p.second;
		}
		else if(p.second > mx2) {
			mx2 = p.second;
		}
	}
	cout << mx1 * mx2 << endl;
}

void part2(vector<Monkey> monkeys) {
	map<ll, ll> id_to_num_inspections_map;
	// calculate the lcm of each divisible_by
	ll k = monkeys[0].divisible_by;
	for(Monkey m : monkeys) {
		k = lcm(k, m.divisible_by);
	}
	for(int round=1;round<=10000;round++) {
		for(Monkey &m : monkeys) {
			id_to_num_inspections_map[m.id] += (ll)m.items.size();
			while(!m.items.empty()) {
				ll item = m.items.front();
				item %= k;
				m.items.pop();
				item = update_item(item, m.op);
				if(item % m.divisible_by == 0) {
					monkeys[m.throw_to_true].items.push(item);
				}
				else {
					monkeys[m.throw_to_false].items.push(item);
				}
			}
		}
	}
	ll mx1 = 0, mx2 = 0;
	for(auto p : id_to_num_inspections_map) {
		if(p.second > mx1) {
			mx2 = mx1;
			mx1 = p.second;
		}
		else if(p.second > mx2) {
			mx2 = p.second;
		}
	}
	cout << mx1 * mx2 << endl;
}

int main() {
	vector<Monkey> monkeys;
	string s;
	int pos;
	string token;
	while(getline(cin, s)) {
		pos = s.find(" ");
		if(s.substr(0, pos) == "Monkey") {
			// get id
			s = s.erase(0, pos + 1);
			pos = s.find(":");
			int id = stoi(s.substr(0, pos));
			// get starting items
			queue<ll> items;
			getline(cin, s);
			pos = s.find(":");
			s.erase(0, pos + 1);
			while((pos = s.find(",")) != std::string::npos) {
				token = s.substr(0, pos);
				items.push(stol(token));
				s.erase(0, pos + 1);
			}
			if(s.length() > 0) {
				items.push(stol(s));
			}
			// get op
			vector<string> op;
			getline(cin, s);
			pos = s.find("= ");
			s.erase(0, pos + 2);
			while((pos = s.find(" ")) != std::string::npos) {
				token = s.substr(0, pos);
				op.push_back(token);
				s.erase(0, pos + 1);
			}
			if(s.length() > 0) {
				op.push_back(s);
			}
			// get divisible_by
			ll divisible_by;
			getline(cin, s);
			pos = s.find("by ");
			s.erase(0, pos + 3);
			divisible_by = stol(s);
			// get throw_to_true
			int throw_to_true;
			getline(cin, s);
			pos = s.find("monkey ");
			s.erase(0, pos + 7);
			throw_to_true = stoi(s);
			// get throw_to_false
			int throw_to_false;
			getline(cin, s);
			pos = s.find("monkey ");
			s.erase(0, pos + 7);
			throw_to_false = stoi(s);
			// build Monkey struct
			Monkey m = {id, throw_to_true, throw_to_false, divisible_by, op, items};
			monkeys.push_back(m);
		}
	}
	part1(monkeys);
	part2(monkeys);
}
