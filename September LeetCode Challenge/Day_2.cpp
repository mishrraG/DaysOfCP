class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, long long> mp;

        if (nums.size() < 2 || k < 1 || t < 0) return false;

        for (int i = 0; i < nums.size(); i++) {
            long long temp = ((long long)nums[i] - (long long)INT_MIN) / ((long long)t + 1);

            if (i > k) {
                long long last = ((long long)nums[i - k - 1] - (long long)INT_MIN) / ((long long)t + 1);
                mp.erase(last);
            }

            if (mp.count(temp) || (mp.count(temp - 1) && abs(mp[temp - 1] - nums[i]) <= t) || (mp.count(temp + 1) && abs(mp[temp + 1] - nums[i]) <= t)) {
                return true;
            }
            mp[temp] = nums[i];
        }

        return false;
    }
};