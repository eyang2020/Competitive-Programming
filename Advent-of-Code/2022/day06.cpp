#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void part1(string s) {
    int n = s.length();
    for(int i=0;i<n-3;i++) {
        set<char> st{s[i], s[i+1], s[i+2], s[i+3]};
        if(st.size() == 4) {
            cout << i + 4 << endl;
            return;
        }
    }
}

void part2(string s) {
    int n = s.length();
    for(int i=0;i<n;i++) {
        set<char> st;
        for(int j=0;j<14&&i+j<n;j++) {
            st.insert(s[i+j]);
        }
        if(st.size() == 14) {
            cout << i + 14 << endl;
            return;
        }
    }
}

int main() {
    string s;
    getline(cin, s);
	part1(s);
	part2(s);
}
