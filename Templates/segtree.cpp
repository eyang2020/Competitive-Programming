#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

/**
 * Source: KACTL
 * Description: Zero-indexed segment tree. 
 * Bounds are inclusive to the left and exclusive to the right. 
 * Check 4 things when instantiate: 
 * (1) type T, (2) function f, (3) appropriate base value unit, 
 * (4) whether update is replace or increment
 */

struct Tree {
    typedef ll T; // change type as needed
    T f(T a, T b) { return a + b; } // (should be associative function)
    int n;
    T unit;
    vector<T> s;
    Tree(int n, T u): s(2*n, u), n(n), unit(u) {  }
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2; )
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n = 1e5 + 1;
    Tree tr(n, 0);
}

int main() {
    IOS
    solve();
    return 0;
}
