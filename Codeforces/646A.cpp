#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            if(a[i]%2==1)
                odd++;
            else
                even++;
        }
        if (x == n) {
            if (odd%2) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        } else {
            if (even > 0 and odd > 0) cout << "Yes" << "\n";
            else if (odd == 0) cout << "No" << "\n";
            else if (x%2) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
        }
    return 0;
}