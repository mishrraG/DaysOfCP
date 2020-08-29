class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int>arr = A, res;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1 ; i >= 0 ; i--)
        {
            auto it = find(A.begin(), A.end(), arr[i]) - A.begin();
            reverse(A.begin(), A.begin() + it + 1);
            res.push_back(it + 1);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};