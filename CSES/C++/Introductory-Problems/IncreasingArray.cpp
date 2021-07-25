#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    ll res = 0, last;
    cin >> last;
    for(int i=1;i<n;i++) {
        ll x;
        cin >> x;
        if(x < last) res += last - x;
        else last = x;
    }
    cout << res << endl;
}
