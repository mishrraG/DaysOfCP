#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        int n, s;
        cin >> n >> s;
        if (2 * n <= s) {
            cout << "YES\n";
            for (int i = 0; i < n - 1; i++) {
                cout << 2 << ' ';
                s -= 2;
            }
            cout << s << '\n' << 1;
        } else {
            cout << "NO";
        }
    }
    return 0;
}