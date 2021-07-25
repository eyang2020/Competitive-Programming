#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0, i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] - k <= b[j] && b[j] <= a[i] + k) {
            i++;
            j++;
            res++;
        }
        else if(a[i] - k > b[j]) j++;
        else i++;
    }
    cout << res << endl;
}
