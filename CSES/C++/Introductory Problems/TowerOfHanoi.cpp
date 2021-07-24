#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

void towerOfHanoi(int n, int a, int b, int c) {
    if(n == 0) return;
    towerOfHanoi(n - 1, a, c, b);
    cout << a << ' ' << c << endl;
    towerOfHanoi(n - 1, b, a, c);
}
 
int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);
}
