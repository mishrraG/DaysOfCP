class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        int maxSub = nums[0];
        int minSub = nums[0];
        int maxProductSub = nums[0];

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minSub, maxSub);
            maxSub = max(maxSub * nums[i], nums[i]);
            minSub = min(minSub * nums[i], nums[i]);
            maxProductSub = max(maxProductSub, maxSub);
        }

        return maxProductSub;
    }

};