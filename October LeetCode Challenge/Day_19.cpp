class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> cntA(7), cntB(7), cntSame(7);
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            cntA[a] += 1;
            cntB[b] += 1;
            if (a == b) cntSame[a] += 1;
        }
        int ans = n;
        for (int v = 1; v <= 6; v++) {
            if (cntA[v] + cntB[v] - cntSame[v] == n) {
                int minSwap = min(cntA[v], cntB[v]) - cntSame[v];
                ans = min(ans, minSwap);
            }
        }
        return ans == n ? -1 : ans;
    }
};