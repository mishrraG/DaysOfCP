class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();

        for (int i = 0; i < n; i++) {
            int a = A[i];
            for (int j = 2; j * j <= a; j++) if (a % j == 0) {
                    vec[j].push_back(i + 1);
                    while (a % j == 0) a /= j;
                }
            if (a > 1) vec[a].push_back(i + 1);
        }

        djs.init(n);
        for (int i = 2; i < MAXA; i++) if ((int) vec[i].size() >= 2) {
                int temp = vec[i][0];
                for (int j = 1; j < (int) vec[i].size(); j++) djs.merge(temp, vec[i][j]);
            }

        int ans = 1;
        for (int i = 1; i <= n; i++) ans = max(ans, djs.size[djs.find(i)]);
        return ans;
    }

private:
    static constexpr int MAXA = 100005;
    static constexpr int MAXN = 20005;
    vector<int> vec[MAXA];

    struct DJS {
        int f[MAXN], size[MAXN];

        void init(int n) {
            for (int i = 1; i <= n; i++) {
                f[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (x == f[x]) return x;
            size[f[x]] += size[x];
            size[x] = 0;
            return f[x] = find(f[x]);
        }

        void merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            f[y] = x;
            size[x] += size[y];
            size[y] = 0;
        }
    } djs;
};