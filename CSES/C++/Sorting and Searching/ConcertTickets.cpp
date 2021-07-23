#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n, m, x;
    cin >> n >> m;
    multiset<int, greater<int>> ms;
    for(int i=0;i<n;i++) {
        cin >> x;
        ms.insert(x);
    }
    while(m--) {
        cin >> x;
        auto it = ms.lower_bound(x);
        if(it == ms.end()) cout << -1 << endl;
        else {
            cout << *it << endl;
            ms.erase(it);
        }
    }
}
