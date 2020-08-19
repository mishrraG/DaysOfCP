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
  w(t) {
    string oper;
    cin >> oper;
    long long x1, y1;
    cin >> x1 >> y1;
    long long countL = 0, countR = 0, countU = 0, countD = 0;
    for (char ch : oper)
    {
      if (ch == 'L')
        countL++;
      else if (ch == 'R')
        countR++;
      else if (ch == 'U')
        countU++;
      else
        countD++;
    }
    long long q;
    cin >> q;

    while (q--)
    {
      int x2, y2;
      cin >> x2 >> y2;
      int reqX = (x2 - x1);
      int reqY = (y2 - y1);
      bool satX = false, satY = false;
      if (reqX > 0)
      {
        if (reqX <= countR)
          satX = true;
      }
      else if (reqX < 0)
        satX = (abs(reqX) <= countL);
      else
        satX = true;

      if (reqY > 0)
      {
        if (reqY <= countU)
          satY = true;
      }
      else if (reqY < 0)
        satY = (abs(reqY) <= countD);
      else
        satY = true;

      if (satX && satY)
        cout << "YES " << abs(reqX) + abs(reqY) << "\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}