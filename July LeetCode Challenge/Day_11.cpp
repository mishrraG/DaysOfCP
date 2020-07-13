class Solution {
public:
    vector<int>FindSubSet(int no, vector<int>&nums) {
        vector<int>re;
        int i = 0;
        while (no) {
            if (no & 1) {
                re.push_back(nums[i]);
            }
            i++;
            no >>= 1;
        }
        return re;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            vector<int>temp = FindSubSet(i, nums);
            ans.push_back(temp);
        }
        return ans;
    }
};