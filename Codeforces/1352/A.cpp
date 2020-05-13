//https://codeforces.com/contest/1352/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        int power = 1;
        while (n > 0) {
            if (n % 10 > 0) {
                ans.push_back((n % 10) * power);
            }
            n /= 10;
            power *= 10;
        }
        cout << ans.size() << endl;
        for (auto number : ans) cout << number << " ";
        cout << endl;
    }
}