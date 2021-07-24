#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> a, b;
    ll sum = n * (n + 1) / 2;
    if(sum % 2 == 0) {
        ll cur = sum / 2;
        for(ll i=n;i>=1;i--) {
            if(i <= cur) {
                a.push_back(i);
                cur -= i;
            }
            else b.push_back(i);
        }
        cout << "YES" << endl;
        cout << a.size() << endl;
        for(auto x : a) cout << x << ' ';
        cout << endl;
        cout << b.size() << endl;
        for(auto x : b) cout << x << ' ';
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
