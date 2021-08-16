#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int main() {
    // time complexity: O(nlog^2n)
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    // k = 0
    vector<pair<char, int>> a(n);
    for(int i=0;i<n;i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1;i<n;i++) c[p[i]] = ((a[i].first == a[i-1].first) ? c[p[i-1]] : c[p[i-1]] + 1);
    // transitions
    int k = 0;
    while((1 << k) < n) {
        // k -> k + 1
        vector<pair<pair<int, int>, int>> a(n);
        for(int i=0;i<n;i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());
        for(int i=0;i<n;i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1;i<n;i++) c[p[i]] = ((a[i].first == a[i-1].first) ? c[p[i-1]] : c[p[i-1]] + 1);
        k++;
    }
    for(int i=0;i<n;i++) cout << p[i] << ' ';
    cout << endl;
}
