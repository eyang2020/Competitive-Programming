#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    if(n <= 3) cout << "NO SOLUTION" << endl;
    else {
        if(n % 2 == 0) {
            for(int i=n-1;i>0;i-=2) cout << i << ' ';
            for(int i=n;i>0;i-=2) cout << i << ' ';
        }
        else {
            for(int i=n;i>0;i-=2) cout << i << ' ';
            for(int i=n-1;i>0;i-=2) cout << i << ' ';
        }
        cout << endl;
    }
}
