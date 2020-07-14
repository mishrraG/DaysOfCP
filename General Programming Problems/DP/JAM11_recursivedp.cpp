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
int dp[100001];

int stairs(int n){
    if(n<=2)
    return n;
    if(n==3)
    return 4;
    if(dp[n]!=-1)
    return dp[n];
    else
    dp[n]=(stairs(n-1)+stairs(n-2)+stairs(n-3))%mod;
    return dp[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(dp, -1, sizeof(dp));
    //init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << stairs(n) << '\n';
    }
    return 0;
}