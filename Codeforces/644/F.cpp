#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
char a[100][100] ;
char final_string[100];
bool isok() {
    for (ll i = 2; i <= n; i++) {
        ll c = 0;
        for (ll j = 1; j <= m; j++) {
            if (final_string[j] != a[i][j])
                c++;
        }

        if (c > 1)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (ll j = 1; j <= m; j++) {
            final_string[j] = a[1][j];
        }
        ll flag = 0;
        for (ll i = 1; i <= m; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                final_string[i] = c;
                if (isok()) {
                    for (ll i = 1; i <= m; i++) {
                        cout << final_string[i];
                    } cout << "\n";
                    flag = 1;
                    break;
                }
            }
            final_string[i] = a[1][i];
            if (flag == 1)
                break;
        }

        if (flag == 0)
            cout << "-1" << "\n";

    }
    return 0;
}