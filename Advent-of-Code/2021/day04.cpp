
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;

vector<int> a;
int grids[100][5][5];
bool vis[100][5][5];

void part1() {
	for(auto x : a) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<5;j++) {
				for(int k=0;k<5;k++) {
					if(grids[i][j][k] == x) { 
						vis[i][j][k] = 1;
					}
				}
			}
			// check win
			for(int j=0;j<5;j++) {
				int rowSum = 0;
				int colSum = 0;
				for(int k=0;k<5;k++) {
					rowSum += vis[i][j][k];
					colSum += vis[i][k][j];
				}
				if(rowSum == 5 || colSum == 5) {
					// win on this board
					int sum = 0;
					for(int l=0;l<5;l++) {
						for(int m=0;m<5;m++) {
							if(vis[i][l][m] == 0) {
								sum += grids[i][l][m];
							}
						}
					}
					cout << x * sum << endl;
					return;
				}
			}
		}
	}
}

void part2() {
	int last = -1; // index of last winning board
	int num = -1; // winning number called
	int sum = 0;
	set<int> st;
	for(auto x : a) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<5;j++) {
				for(int k=0;k<5;k++) {
					if(grids[i][j][k] == x) { 
						vis[i][j][k] = 1;
					}
				}
			}
			// check win
			for(int j=0;j<5;j++) {
				int rowSum = 0;
				int colSum = 0;
				for(int k=0;k<5;k++) {
					rowSum += vis[i][j][k];
					colSum += vis[i][k][j];
				}
				if(rowSum == 5 || colSum == 5) {
					// win on this board
					if(st.count(i)) {
						continue;
					}
					last = i;
					num = x;
					st.insert(i);
					sum = 0;
					for(int l=0;l<5;l++) {
						for(int m=0;m<5;m++) {
							if(vis[i][l][m] == 0) {
								sum += grids[i][l][m];
							}
						}
					}
				}
			}
		}
	}
	cout << num * sum << endl;
}

int main() {
	string s;
	getline(cin, s);
	int pos = 0;
	string delim = ",";
	string token;
	while ((pos = s.find(delim)) != string::npos) {
		token = s.substr(0, pos);
		a.push_back(stoi(token));
		s.erase(0, pos + delim.length());
	}
	a.push_back(stoi(s));
	n = 0;
	while(getline(cin, s) && s == "") {
		for(int i=0;i<5;i++) {
			getline(cin, s);
			delim = " ";
			int j = 0;
			while ((pos = s.find(delim)) != string::npos) {
				token = s.substr(0, pos);
				s.erase(0, pos + delim.length());
				if(token == "") continue;
				grids[n][i][j] = stoi(token);
				j++;
			}
			grids[n][i][j] = stoi(s);
		}
		n++;
	}
	//part1();
	part2();
}
