#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void part1(vector<string> a) {
    int n = a.size(), res = 0;
    for(string s : a) {
        int m = s.length(), cur = 0;
        for(int i=0;i<m;i++) {
            if (isdigit(s[i])) {
                cur = (s[i] - '0') * 10;
                break;
            }
        }
        for(int i=m-1;i>=0;i--) {
            if (isdigit(s[i])) {
                cur += (s[i] - '0');
                break;
            }
        }
        res += cur;
    }
    cout << res << endl;
}

void part2(vector<string> a) {
    int n = a.size(), res = 0;
    for (string s : a) {
        int m = s.length(), cur = 0, lIdx = INF, rIdx = -1, lVal = 0, rVal = 0;
        for(int i=0;i<m;i++) {
            if (isdigit(s[i])) {
                lIdx = i;
                lVal = (s[i] - '0');
                break;
            }
        }
        for(int i=m-1;i>=0;i--) {
            if (isdigit(s[i])) {
                rIdx = i;
                rVal = (s[i] - '0');
                break;
            }
        }
        for(int i=0;i<9;i++) {
            string digit = digits[i];
            if (s.find(digit) != string::npos) {
                if (s.find(digit) < lIdx) {
                    lIdx = s.find(digit);
                    lVal = i + 1;
                }
            }
            if (s.rfind(digit) != string::npos) {
                if (s.rfind(digit) > rIdx) {
                    rIdx = s.rfind(digit);
                    rVal = i + 1;
                }
            }
        }
        res += lVal * 10 + rVal;
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
	vector<string> a;
	while(getline(cin, s)) {
		a.push_back(s);
	}
	//part1(a);
	part2(a);
}
