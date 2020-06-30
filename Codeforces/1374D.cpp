#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int p[100005];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        map<int, int> cnt;
        int mx = 0;
        for (auto &it : a) {
            if (it % k == 0) continue;
            ++cnt[k - it % k];
            mx = max(mx, cnt[k - it % k]);
        }
        int ans = 0;
        for (auto [key, value] : cnt) {
            if (value == mx) {
                ans = k * (value - 1) + key + 1;
            }
        }
        cout << ans << endl;
    }
}