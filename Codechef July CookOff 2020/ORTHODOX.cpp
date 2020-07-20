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
const int N = 1e5 + 9;
const long long M = 1e18;

long long a[N];
int32_t main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int sum=0;
    w(t){
        int n;
        cin >> n;
        sum += n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (n > 60)
        {
            cout << "NO\n";
            continue;
        }
        set<long long> se;
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            long long cur = 0;
            for (int j = i; j <= n; j++)
            {
                cur |= a[j];
                if (se.find(cur) != se.end())
                {
                    ok = false;
                    break;
                }
                se.insert(cur);
            }
            if (!ok)
                break;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}