#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n, res = 0;
    cin >> n;
    map<int, int> last;
    for(int i=0,j=0;i<n;i++) {
        int x;
        cin >> x;
        j = max(j, last[x]);
        last[x] = i + 1;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
}
