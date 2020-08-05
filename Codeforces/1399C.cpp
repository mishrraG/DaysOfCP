#include<bits/stdc++.h>
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
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<int>st;
        int freq = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
            {
                st.insert(a[i] + a[j]);
            }
        }
        for (auto c : st)
        {
            vector<bool> taken(n, false);
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (taken[i] || taken[j] || i == j)
                        continue;
                    if (a[i] + a[j] == c)
                    {
                        taken[i] = true;
                        taken[j] = true;
                        cur++;
                    }
                }
            }
            if (ans < cur)
                ans = cur;
        }
        cout << ans << '\n';
    }
    return 0;
}