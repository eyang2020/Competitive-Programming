#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    cout << n << ' ';
    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        cout << n << ' ';
    }
    cout << endl;
}
