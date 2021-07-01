#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<char, int> mp;
    for(auto c : s) mp[c]++;
    bool ok = true;
    char odd = '?';
    for(auto p : mp) {
        if(p.second % 2 == 1) {
            if(odd != '?') {
                cout << "NO SOLUTION" << endl;
                ok = false;
                break;
            }
            else odd = p.first;
        }
    }
    if(ok) {
        string res;
        for(auto p : mp) {
            char c = p.first;
            int cnt = p.second;
            res += string(cnt / 2, c);
        }
        if(odd == '?') cout << res + string(res.rbegin(), res.rend()) << endl;
        else cout << res + odd + string(res.rbegin(), res.rend());
    }
}
