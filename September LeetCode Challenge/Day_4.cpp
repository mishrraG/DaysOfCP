class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v;
        vector<int> last(26, 0);
        for (int i = 0; i < S.length(); i++)
        {
            last[S[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;
        for (int i = 0; i < S.length(); i++)
        {
            j = max(j, last[S[i] - 'a']);
            if (i == j)
            {
                v.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return v;
    }
};