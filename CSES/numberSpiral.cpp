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
  int y,x;
  w(t){
    cin >> y >> x;
    int a = max(y, x);
    int b = min(y, x);
    int s = ((a - 1) * (a - 1));
    if (a == b)
      s += a;
    else if (a % 2)
    {
      if (x == a)
        s += a * 2 - y;
      else
        s += x;
    }
    else
    {
      if (y == a)
        s += a * 2 - x;
      else
        s += y;
    }
    cout << s << endl;
  }
    return 0;
}