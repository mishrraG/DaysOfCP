class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x] += 1;
        int ans = 0;
        for (auto [b, _] : cnt)
            if ((k > 0 && cnt.count(b - k)) || (k == 0 && cnt[b] >= 2))
                ans += 1;
        return ans;
    }
};