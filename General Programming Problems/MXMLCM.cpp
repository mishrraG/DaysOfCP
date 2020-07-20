
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define T ll t = 1; cin>>t; while(t--)
#define ain ll n,k,i; cin>>n; ll a[n]; for(i=0; i<n; i++) cin>>a[i]
#define matin ll m,n; cin >> n >> m; ll a[n + 1][m + 1]; for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin>>a[i][j];
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define I insert
#define pb push_back
const int MAX = 2e4 + 5;
int fastpow(int a,int b)
    {
        int res = 1;
        while(b > 0)
        {
            if(b & 1)
            {
                res = res * a;
            }
            b = b / 2;
            a = a * a;
        }
        return res;
    }

    int isprime[MAX];
    vector<int>X;
    int mp[MAX];
    void sieve()
    {
       for(int i = 1;i < MAX;++i)
           isprime[i] = i;

        for(int i = 2;i < MAX;++i)
        {
            if(i == isprime[i])
            {
                for(int j = 2 * i;j <= MAX;j += i)
                {
                    if(isprime[j] == j)
                    isprime[j] = i;
                }
            }
        }

    }

 int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        sieve();
        T{
            memset(mp,0,sizeof mp);
            int n,m,i;
            cin >> n >> m;
            int x;
            for(i = 0;i < n;++i)
            {
                cin >> x;
                while(x > 1)
                {
                    int val = isprime[x];
                    int cnt = 0;
                    while(isprime[x] == val)
                    {
                        x /= isprime[x];
                        cnt++;
                    }
                    
                    mp[val] = max(mp[val],cnt);
                }
            }
            
            int maxx = 1;
            int minn = 1;
            
            for(i = 2;i <= m;++i)
            {
                int ans = 1;
                x = i;
                while(x > 1)
                {
                    int val = isprime[x];
                    int cnt = 0;
                    while(isprime[x] == val)
                    {
                        x /= isprime[x];
                        cnt++;
                    }
                    if(cnt > mp[val])
                       ans *= fastpow(val,cnt-mp[val]);
                }
                
                if(ans > maxx)
                {
                    maxx = ans;
                    minn = i;
                }
            }
           
            cout << minn << '\n';
            
        }
     
    }