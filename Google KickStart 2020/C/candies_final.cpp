#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, vector<char>& oper) {
    int ans = 0;
    if (oper[0] == 'U') {
        arr[(oper[1] - '0') - 1] = oper[2] - '0';
    }
    else {
        int l = oper[1] - '0';
        int r = oper[2] - '0';
        int c = 1, sign = 1;
        for (int i=l-1; i<r; i++) {
            ans += arr[i] * sign * c++;
            if (sign == 1)
                sign = -1;
            else
                sign = 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        int ans = 0;
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for (int i=0; i<k; i++) {
            vector<char> oper(3);
            for (int j=0; j<3; j++) {
                if (j == 0) cin >> oper[j];
                else {
                    int c;
                    cin >> c;
                    oper[j] = c + '0';
                }
            }
            ans += solve(arr, oper);
        }
        cout << "Case #" << c++ << ": " << ans << endl;
    }
    return 0;
}