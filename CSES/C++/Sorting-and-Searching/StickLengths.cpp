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
    ll res = 0, med = a[n/2];
    for(int i=0;i<n;i++) res += abs(med - a[i]);
    cout << res << endl;
}
