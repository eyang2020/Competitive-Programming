#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n, res = 0;
    cin >> n;
    for(int i=5;n/i>=1;i*=5) res += n / i;
    cout << res << endl;
}
