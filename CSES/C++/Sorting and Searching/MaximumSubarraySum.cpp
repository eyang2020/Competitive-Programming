#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    ll curMx = 0, bestMx = -1e12;
    for(int i=0;i<n;i++) {
        ll x;
        cin >> x;
        curMx += x;
        bestMx = max(bestMx, curMx);
        curMx = max(curMx, 0LL);
    }
    cout << bestMx << endl;
}
