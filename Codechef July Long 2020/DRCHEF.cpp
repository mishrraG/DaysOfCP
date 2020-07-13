#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define umii unordered_map<int, int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    int cp = x;
    int ctr;
    ctr = lower_bound(a, a + n, x) - a;
    int d = 0;
    int total = ctr;
    int lower = ctr;
    for (int i = lower; i < n; i++)
    {
      if (x < a[i])
      {
        while (x < a[i])
        {
          x += x;
          d++;
        }
        d++;
      }
      else
        d++;
      x = a[i] + a[i];
    }
    total += d;
    if (lower!=0)
    {
      lower -= 1;
      d = 0;
      for (int i = lower ; i < n; i++)
      {
        if (x < a[i])
        {
          while (x < a[i])
          {
            x += x;
            d++;
          }
          d++;
        }
        else
          d++;
        x = a[i] + a[i];
      }
      if (d+lower < total )
        cout << d + lower  << '\n';
      else
        cout << total << '\n';
    }
    else
      cout << total << '\n';

  }
  return 0;
}