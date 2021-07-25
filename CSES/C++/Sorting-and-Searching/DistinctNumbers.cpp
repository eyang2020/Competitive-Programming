#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    int last = -1, cnt = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) {
        if(a[i] != last) {
            cnt++;
            last = a[i];
        }
    }
    cout << cnt << endl;
}
