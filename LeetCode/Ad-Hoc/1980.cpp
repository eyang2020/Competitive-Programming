class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string res;
        for(int i=0;i<n;i++) {
            res += (nums[i][i] == '1') ? '0' : '1';
        }
        return res;
    }
};
