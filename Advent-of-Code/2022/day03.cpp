#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

set<char> get_intersection(string a, string b) {
    set<char> st;
    for(char c1 : a) {
        for(char c2 : b) {
            if(c1 == c2) {
                st.insert(c1);
            }
        }
    }
    return st;
}

int get_score(char c) {
    int res = 0;
    if(isupper(c)) {
        res += c - 'A' + 27;
    }
    else {
        res += c - 'a' + 1;
    }
    return res;
}

void part1(vector<string> v) {
    int res = 0;
    for(string s : v) {
        int n = s.length();
        string a = s.substr(0, n / 2);
        string b = s.substr(n / 2);
        set<char> st = get_intersection(a, b);
        for(char c : st) {
            res += get_score(c);
        }
    }
    cout << res << endl;
}

void part2(vector<string> v) {
    int n = v.size();
    int res = 0;
    for(int i=0;i<n;i+=3) {
        string a = v[i], b = v[i+1], c = v[i+2];
        set<char> st1 = get_intersection(a, b);
        set<char> st2 = get_intersection(b, c);
        for(char c1 : st1) {
            if(st2.count(c1)) {
                res += get_score(c1);
                break;
            }
        }
    }
    cout << res << endl;
}

int main() {
    string s;
    vector<string> v;
    while(getline(cin, s)) {
        v.push_back(s);
    }
	part1(v);
	part2(v);
}
