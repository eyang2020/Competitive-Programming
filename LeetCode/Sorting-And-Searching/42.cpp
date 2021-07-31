class Solution {
public:
	// O(n) time , O(1) Space 
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1, lMax = 0, rMax = 0;
        while(l<=r){
            lMax = max(lMax , height[l]);
            rMax = max(rMax , height[r]);
            if (lMax < rMax) {
                res += lMax - height[l];
                l++;
            }
            else {
                res += rMax-height[r];
                r--;
            }
        }
        return res;
    }
};
