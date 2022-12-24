#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e7;
const int M = 4e6;

ll man_dist(pair<ll, ll> p1, pair<ll, ll> p2) {
	ll x1 = p1.first, y1 = p1.second;
	ll x2 = p2.first, y2 = p2.second;
	return abs(x2 - x1) + abs(y2 - y1);
}

void part1(vector<pair<ll, ll>> sensors, vector<pair<ll, ll>> beacons) {
	int n = sensors.size();
	ll y = 2e6;
	set<pair<ll, ll>> st;
	for(ll x=-N;x<=N;x++) {
		for(int i=0;i<n;i++) {
			ll d1 = man_dist({x, y}, sensors[i]);
			ll d2 = man_dist(sensors[i], beacons[i]);
			if(d1 <= d2) {
				st.insert({x, y});
				break;
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(beacons[i].second == y) {
			st.erase(beacons[i]);
		}
	}
	cout << st.size() << endl;
}

void part2(vector<pair<ll, ll>> sensors, vector<pair<ll, ll>> beacons) {
	vector<ll> pos_slope, neg_slope;
	int n = sensors.size();
	for(int i=0;i<n;i++) {
		ll d = man_dist(sensors[i], beacons[i]);
		int x = sensors[i].first, y = sensors[i].second;
		pos_slope.push_back(y - x + d + 1);
		pos_slope.push_back(y - x - d - 1);
		neg_slope.push_back(x + y + d + 1);
		neg_slope.push_back(x + y - d - 1);
	}
	bool done = false;
	ll res = 0;
	for(ll a : pos_slope) {
		for(ll b : neg_slope) {
			pair<ll, ll> p = {(b - a) / 2, (a + b) / 2};
			if(0 <= p.first && p.first <= M && 0 <= p.second && p.second <= M) {
				bool ok = true;
				for(int i=0;i<n;i++) {
					ll d1 = man_dist(sensors[i], beacons[i]);
					ll d2 = man_dist(sensors[i], p);
					if(d2 <= d1) {
						ok = false;
						break;
					}
				}
				if(ok) {
					res = p.first * M + p.second;
					done = true;
					break;
				}
			}
		}
		if(done) {
			break;
		}
	}
	cout << res << endl;
}

int main() {
	vector<pair<ll, ll>> sensors, beacons;
	string s;
	while(getline(cin, s)) {
		s.erase(0, s.find("=") + 1);
		ll x1 = stol(s.substr(0, s.find(",")));
		s.erase(0, s.find("=") + 1);
		ll y1 = stol(s.substr(0, s.find(":")));
		s.erase(0, s.find("=") + 1);
		ll x2 = stol(s.substr(0, s.find(",")));
		s.erase(0, s.find("=") + 1);
		ll y2 = stol(s.substr(0, s.find(":")));
		sensors.push_back({x1, y1});
		beacons.push_back({x2, y2});	
	}
	part1(sensors, beacons);
	part2(sensors, beacons);
}
