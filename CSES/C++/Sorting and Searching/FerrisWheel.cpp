#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, res = 0;
    while(i <= j) {
        if(a[i] + a[j] <= x) i++;
        res++;
        j--;
    }
    cout << res << endl;
}
