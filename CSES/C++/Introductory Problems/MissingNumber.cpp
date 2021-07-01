#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n-1;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int cur = 1;
    for(int i=0;i<n-1;i++) {
        if(cur == v[i]) cur++;
        else {
            cout << cur << endl;
            break;
        }
    }
    if(cur == n) cout << n << endl;
}
