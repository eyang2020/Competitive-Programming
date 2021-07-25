class Solution {
public:
    // Time Complexity = O(n * log(n))
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++) {
            if(i == 0) res.push_back(nums[i]);
            else {
                auto x = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                if(x >= res.size()) res.push_back(nums[i]);
                else res[x] = nums[i];
            }
        }
        return res.size();
    }
};
