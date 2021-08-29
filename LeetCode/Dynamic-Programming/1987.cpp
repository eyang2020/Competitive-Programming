class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numberOfUniqueGoodSubsequences(string binary) {
        vector<int> dp(2);
        for(auto c : binary) {
            dp[c-'0'] = (dp[0] + dp[1] + (c - '0')) % MOD;
        }
        return (dp[0] + dp[1] + (binary.find("0") != string::npos)) % MOD;
    }
};
