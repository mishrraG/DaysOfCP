#include <bits/stdc++.h>
using namespace std;
int n, b, a[100000];
void solve() {
    cin >> n >> b;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int ans=0;
    for(int i=0; i<n; ++i) {
        if(b>=a[i]) {
            b-=a[i];
            ++ans;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, i=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
}