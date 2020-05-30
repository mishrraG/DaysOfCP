#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
void solve() {
    ll m, n;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            v[i] *= 2;
            v[i] += c - '0';
        }
    }
    ll need = ((1ll << m) - n - 1) / 2 + 1;
    ll cur = (1ll << (m - 1)) - 1;
    while (true) {
        ll left = cur + 1;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            flag |= v[i] == cur;
            if (v[i] <= cur) {
                left--;
            }
        }
        if (left == need && !flag) {
            string s;
            for (int i = 0; i < m; i++) {
                s += (char)(cur % 2 + '0');
                cur /= 2;
            }
            reverse(s.begin(), s.end());
            cout << s << endl;
            return;
        } else if (left < need) {
            cur++;
        } else {
            cur--;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}