#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    /* this is for gray codes in decimal form
    for(int i=0;i<(n<<1);i++) {
        cout << (i ^ (i >> 1)) << endl;
    }
    */
    vector<string> res = {"0", "1"};
    int i, j;
    for(i=2;i<(1<<n);i<<=1) {
        for(j=i-1;j>=0;j--) res.push_back(res[j]);
        for(j=0;j<i;j++) res[j] = "0" + res[j];
        for(j=i;j<i*2;j++) res[j] = "1" + res[j];
    }
    for(auto s : res) cout << s << endl;
}
