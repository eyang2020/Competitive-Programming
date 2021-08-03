class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_set<string> vis;
        int size = 1 << n;
        for(int mask=0;mask<size;mask++) {
            vector<int> subset;
            string hashcode;
            for(int j=0;j<n;j++) {
                if(mask & (1 << j)) {
                    subset.push_back(nums[j]);
                    hashcode += to_string(nums[j]) + ',';
                }
            }
            if(!vis.count(hashcode)) {
                vis.insert(hashcode);
                res.push_back(subset);
            }
        }
        
        return res;
    }
};
