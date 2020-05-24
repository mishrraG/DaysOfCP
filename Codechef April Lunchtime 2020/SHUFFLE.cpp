//https://www.codechef.com/LTIME83B/problems/SHUFFLE
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int x;
        for (int i = 0; i+k < n; i++) {
            if (a[i] > a[i + k]) {
                int p = a[i];
                a[i] = a[i + k];
                a[i + k] = p;
                x = i;
                while ((((x - k) >= 0)) && a[x - k] > a[x]) {
                    p = a[x];
                    a[x] = a[x - k];
                    a[x - k] = p;
                    x = x - k;
                }
            }
        }
        is_sorted(a,a+n)?cout << "yes\n":cout << "no\n";
    }
}