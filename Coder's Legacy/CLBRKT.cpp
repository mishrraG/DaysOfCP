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
    w(t){
        string s;
        cin >> s;
        int q;
        cin >> q;
        int n = s.length();
        stack<int> st;
        vector<int> nxt(n, -2);
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (st.size() > 0)
                nxt[st.top()] = i, st.pop();
        }
        for (i = n - 2; i >= 0; i--)
        {
            if (s[i] == ')')
                nxt[i] = nxt[i + 1];
        }
        while (q--)
        {
            int p;
            cin >> p;
            cout << nxt[p-1]+1 << '\n';
        }
    }
    return 0;
}