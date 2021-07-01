#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    string s;
    cin >> s;
    int n = s.length(), cur = 1, best = 1;
    char last = s[0];
    for(int i=1;i<n;i++) {
        if(s[i] == last) cur++;
        else {
            last = s[i];
            best = max(best, cur);
            cur = 1;
        }
    }
    best = max(best, cur);
    cout << best << endl;
}
