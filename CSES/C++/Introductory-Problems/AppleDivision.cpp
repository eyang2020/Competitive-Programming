#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

int main() {
    IOS
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll res = 1e18;
    for(int i=0;i<(1<<n);i++) {
        ll sum1 = 0, sum2 = 0;
        for(int j=0;j<n;j++) {
            if(i & (1 << j)) {
                sum1 += a[j];
            }
            else {
                sum2 += a[j];
            }
        }
        res = min(res, abs(sum2 - sum1));
    }
    cout << res << endl;
    return 0;
}
