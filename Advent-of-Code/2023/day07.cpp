#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int dxWithDiag[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dyWithDiag[8] = {1, 0, -1, 0, -1, 1, 1, -1};

const char CARDS[13] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
const char CARDS_WITH_JOKER[13] = {'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'};

ll modpow(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    if(x == 0) return 0;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

vector<string> tokenize(string s, string delim) {
    vector<string> tokens;
    int idx = 0, n = delim.length();
    string token;
    while((idx = s.find(delim)) != string::npos) {
        token = s.substr(0, idx);
        tokens.push_back(token);
        s.erase(0, idx + n);
    }
    tokens.push_back(s);
    return tokens;
}

int getHandType(string hand) {
    map<char, int> cnt;
    for(char c : hand) cnt[c]++;
    if(cnt.size() == 1) {
        // Five of a kind
        return 6;
    }
    if(cnt.size() == 2) {
        for(auto p : cnt) {
            if(p.second == 4) {
                // Four of a kind
                return 5;
            }
            if(p.second == 3) {
                // Full house
                return 4;
            }
        }
    }
    if(cnt.size() == 3) {
        int cnt1 = 0, cnt2 = 0;
        for(auto p : cnt) {
            if(p.second == 1) {
                cnt1++;
            }
            if(p.second == 2) {
                cnt2++;
            }
        }
        if(cnt1 == 2) {
            // Three of a kind
            return 3;
        }
        if(cnt2 == 2) {
            // Two pair
            return 2;
        }
    }
    if(cnt.size() == 4) {
        int cnt2 = 0;
        for(auto p : cnt) {
            if(p.second == 2) {
                cnt2++;
            }
        }
        if(cnt2 == 1) {
            // One pair
            return 1;
        }
    }
    // High card
    return 0;
}

int getHandTypeWithJoker(string hand) {
    int maxHandType = 0;
    for(int i=0;i<13;i++) {
        string temp = hand;
        for(int j=0;j<5;j++) {
            if(temp[j] == 'J') {
                temp[j] = CARDS[i];
            }
        }
        maxHandType = max(maxHandType, getHandType(temp));
    }
    return maxHandType;
}

void part1(vector<pair<string, ll>> a) {
    ll res = 0;
    int n = a.size();
    sort(a.begin(), a.end(), [](const auto& p1, const auto& p2) {
        int handType1 = getHandType(p1.first);
        int handType2 = getHandType(p2.first);
        if(handType1 == handType2) {
            for(int i=0;i<5;i++) {
                char c1 = p1.first[i];
                char c2 = p2.first[i];
                if(c1 == c2) {
                    continue;
                }
                int idx1 = 0, idx2 = 0;
                for(int j=0;j<13;j++) {
                    if(CARDS[j] == c1) {
                        idx1 = j;
                    }
                    if(CARDS[j] == c2) {
                        idx2 = j;
                    }
                }
                return idx1 >= idx2;
            }
        }
        return handType1 < handType2;
    });
    for(int i=0;i<n;i++) {
        res += a[i].second * (i + 1);
    }
    cout << res << endl;
}

void part2(vector<pair<string, ll>> a) {
    ll res = 0;
    int n = a.size();
    sort(a.begin(), a.end(), [](const auto& p1, const auto& p2) {
        int handType1 = getHandTypeWithJoker(p1.first);
        int handType2 = getHandTypeWithJoker(p2.first);
        if(handType1 == handType2) {
            for(int i=0;i<5;i++) {
                char c1 = p1.first[i];
                char c2 = p2.first[i];
                if(c1 == c2) {
                    continue;
                }
                int idx1 = 0, idx2 = 0;
                for(int j=0;j<13;j++) {
                    if(CARDS_WITH_JOKER[j] == c1) {
                        idx1 = j;
                    }
                    if(CARDS_WITH_JOKER[j] == c2) {
                        idx2 = j;
                    }
                }
                return idx1 >= idx2;
            }
        }
        return handType1 < handType2;
    });
    for(int i=0;i<n;i++) {
        res += a[i].second * (i + 1);
    }
    cout << res << endl;
}

int main() {
    IOS
    string s;
    vector<pair<string, ll>> a;
    while(getline(cin, s)) {
        vector<string> b = tokenize(s, " ");
        a.push_back({b[0], stol(b[1])});
    }
    part1(a);
    part2(a);
    return 0;
}
