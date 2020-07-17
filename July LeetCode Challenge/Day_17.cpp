class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        vector<pair<int, int>> vp;
        for (auto x : mp)
        {
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end(), greater<>());
        vector<int> ans;
        for (auto x : vp)
        {
            ans.push_back(x.second);
            if (ans.size() == k)
                break;
        }
        return ans;

    }
};