#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int t2 = 1;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int res = 1e9;
    for(char c='A';c<='Z';c++) {
        int cur = 0;
        bool vowel = isVowel(c);
        for(auto c2 : s) {
            if(c2 == c) continue;
            if(vowel == isVowel(c2)) {
                cur += 2;
            }
            else cur++;
        }
        res = min(res, cur);
    }
    cout << "Case #" << t2++ << ": " << res << endl;
}

int main() {
    IOS
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
