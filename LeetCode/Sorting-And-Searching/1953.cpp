class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long sum = 0;
        for(auto x : milestones) sum += (long long)x;
        long long rest = sum - (long long)mx;
        return min(2 * rest + 1, sum);
    }
};
