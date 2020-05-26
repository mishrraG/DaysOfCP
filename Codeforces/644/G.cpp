#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        if (n * a != m * b) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            ll final_array[100][100] = {0};
            ll col_sum[100] = {0};
            for (ll i = 1; i <= n; i++) {
                vector<pair<ll, ll>> a_columns;
                for (ll j = 1; j <= m; j++) {
                    if (col_sum[j] < b)
                        a_columns.push_back(make_pair(col_sum[j], j));
                }
                sort(a_columns.begin(), a_columns.end());
                for (ll k = 0; k < a; k++) {
                    col_sum[a_columns[k].second]++;
                    final_array[i][a_columns[k].second] = 1;
                }
            }
            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j <= m; j++) {
                    cout << final_array[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}