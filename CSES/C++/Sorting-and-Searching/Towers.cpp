#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        auto it = ms.upper_bound(x);
        if(it != ms.end()) ms.erase(it);
        ms.insert(x);
    }
    cout << ms.size() << endl;
}
