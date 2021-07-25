#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    int n;
    cin >> n;
    map<int, int> pos;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int res = 1;
    for(int i=1;i<n;i++) if(pos[i] > pos[i+1]) res++;
    cout << res << endl;
}
