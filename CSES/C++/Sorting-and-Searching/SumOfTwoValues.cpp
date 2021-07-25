#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll, int>> a(n);
    for(int i=0;i<n;i++) {
        ll num;
        cin >> num;
        a[i] = {num, i + 1};
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while(i < j) {
        ll sum = a[i].first + a[j].first;
        if(sum == x) {
            cout << a[i].second << ' ' << a[j].second << endl;
            return 0;
        }
        else if(sum < x) i++;
        else j--;
    }
    cout << "IMPOSSIBLE" << endl;
}
