#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int suf0 = 0, suf1 = 0;
        for(auto &it:s)
        {
            suf0 += (it == '0');
            suf1 += (it == '1');
        }
        int ans = min(suf0, suf1);
        int pref0 = 0, pref1 = 0;
        for(auto &it:s)
        {
            pref0 += (it == '0'), suf0 -= (it == '0');
            pref1 += (it == '1'), suf1 -= (it == '1');
            ans = min(ans, pref1 + suf0);
            ans = min(ans, pref0 + suf1);
        }
        cout << ans << endl;
    }
    return 0;
}