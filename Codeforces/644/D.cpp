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
        ll n, k;
        cin >> n >> k;
        if (n <= k) {
            cout << 1 << "\n";
        } else if (k == 1) {
            cout << n << "\n";
        } else {
            vector<ll> fact;
            for (ll i = 1; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    if (n / i == i && i <= k)
                        fact.push_back(i);
                    else {
                        if (i <= k)
                            fact.push_back(i);
                        if (n / i <= k)
                            fact.push_back(n / i);
                    }
                }
            }
            ll ans = 2e9;
            for (ll i = 0; i < fact.size(); i++) {
                if (n % fact[i] == 0) {
                    if (ans > (n / fact[i])) {
                        ans = n / fact[i];
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}