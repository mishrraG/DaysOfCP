class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {

        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() - 1;
        int tmp = 0;
        int res = 0;
        while (l <= r) {

            if (tokens[l] <= P) {
                P -= tokens[l];
                ++tmp;
                ++l;
                res = max(tmp, res);
            } else if (tmp) {
                P += tokens[r];
                --tmp;
                --r;
            } else {
                break;
            }


        }
        return res;
    }
};