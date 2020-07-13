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
#define ps(x, y) fixed << setprecision(y) << x
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
    int n,q;
    cin >> n >> q;
    vi a(n),h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int y,z;
            cin >> y >> z;
            a[y-1]=z;
        }
        if(x==2){
            int y,z;
            cin >> y >> z;
            int dest = y-1;
            int src = z - 1;
            if (src == dest)
            {
                cout << a[src] << '\n';
                continue;
            }
            if (h[dest] <= h[src])
            {
                cout << "-1\n";
                continue;
            }
            int dir = (dest - src) / abs(dest - src);
            int curr = src;
            int total_taste = a[src];
            bool flag = true;
            for (int next = src + dir; next != dest;next += dir)
            {
                if (h[next] >= h[dest])
                {
                    flag = (h[next]<h[dest]);
                }
                if (h[next] > h[curr]  && flag)
                {
                    curr = next;
                    total_taste += a[curr];
                }
            }
            int ans = flag ? (total_taste + a[dest]):(-1);
            cout << ans << '\n';
        }
    }
    return 0;
}