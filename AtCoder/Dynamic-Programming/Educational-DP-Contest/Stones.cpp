#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    // let dp[i] represent whether it is possible for the first player to win with i stones remaining
    vector<bool> dp(k + 1);
    for(int i=0;i<=k;i++) {
        for(auto x : a) {
            if(i >= x && !dp[i-x]) {
                dp[i] = 1;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second") << endl;
}
