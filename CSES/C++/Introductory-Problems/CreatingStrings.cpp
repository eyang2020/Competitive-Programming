#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> res;
    do res.push_back(s);
    while(next_permutation(s.begin(), s.end()));
    cout << res.size() << endl;
    for(auto x : res) cout << x << endl;
}
