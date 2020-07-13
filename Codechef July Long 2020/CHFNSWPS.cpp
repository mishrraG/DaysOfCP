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
#define all(x)          x.begin(),x.end()
#define umii            unordered_map<int,int>
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
int solve(umii,umii,int,set<int>,int);
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
        int n;
        cin >> n;
        vi a(n),b(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];
        sort(all(a));
        sort(all(b));
        umii m1,m2;
        int i=0,j=0,c=0;
        set<int>s;
        while(i<n && j<n){
            if (!(a[i]-b[j]))
            {
                i++;
                j++;
                continue;
            }
            else if (a[i] > b[j])
            {
                m1[b[j++]] += 1;
                s.insert(b[j]);
            }
            else if (b[j] > a[i])
            {
                m2[a[i++]] += 1;
                s.insert(a[i]);
            }
            c++;
        }
        while (i < n)
        {
            m1[a[i++]] += 1;
            c++;
            s.insert(a[i]);
        }
        while (j < n)
        {
            m2[b[j++]] += 1;
            c++;
            s.insert(b[j]);
        }
        c/=4;
        int sm = min(a[0],b[0]);
        cout << solve(m1,m2,c,s,sm) << '\n';
    }
}
int solve(unordered_map<int,int> mymap1, unordered_map<int,int> mymap2, int count, set<int> s, int smallest){
    for (auto i : mymap1)
    {
        if (i.second%2==1)
        {
            return -1;
        }
    }
    for (auto j : mymap2)
    {
        if (j.second%2==1)
        {
            return -1;
        }
    }
    int ans = 0;
    for (auto k : s)
    {
        int r = max(mymap1[k], mymap2[k]);
        if (r / 2 <= count)
        {
            ans+= (k * (r / 2) > 2 * smallest * (r / 2)) ? (2 * smallest * (r / 2)) : (k * (r / 2));
            count -= r / 2;
        }
        else
        {
            ans+=(k >2* smallest)?(smallest*count*2):(k*count);
            count = 0;
        }
        if (!count)
            return ans;
    }
    return ans;
}