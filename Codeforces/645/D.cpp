#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector <int> d(2 * n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = n + 1; i <= 2 * n + 1; i++) {
        d[i] = d[i - n];
    }

    int temp = 0, val = 0;
    int ans = 0, idx = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (temp + d[i] <= x) {
            temp += d[i];
            val += (d[i] * (d[i] + 1)) / 2;
            ans = max(ans, val);
        } else {
            int y = temp + d[i] - x;
            if (y > 0)
                ans = max(ans, val - (y * (y + 1)) / 2 + (d[i] * (d[i] + 1)) / 2);
            temp -= d[idx];
            val -= (d[idx] * (d[idx] + 1)) / 2;
            idx++;
            i--;
        }
    }

    cout << ans << endl;

    return 0;
}