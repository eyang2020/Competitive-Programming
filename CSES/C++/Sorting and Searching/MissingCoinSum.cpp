#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 1;
    for(int i=0;i<n&&a[i]<=res;i++) res += a[i];
    cout << res << endl;
}
