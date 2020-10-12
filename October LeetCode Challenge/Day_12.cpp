class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() < 2) return false;
        string sa, sb;
        bitset<128> bits{0};
        bool dup = false;
        for (int i = 0; i < A.size() && sa.size() <= 2; ++i) {
            if (A[i] != B[i]) {
                sa += A[i], sb += B[i];
            } else {
                dup |= bits.test(A[i]);
                bits.set(A[i]);
            }
        }
        if (sa.size() == 2) {
            swap(sa[0], sa[1]);
            return sa == sb;
        }
        return sa.empty() && dup;
    }
};