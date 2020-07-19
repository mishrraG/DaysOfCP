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
int exponentMod(int A, int B, int C) {
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
    int y;
    if (!(B & 1))
    {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
    else
    {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (int)((y + C) % C);
}
int power(int a, int b)
{
    int aa = 1;
    while (b)
    {

        if (b % 2)
        {
            aa = aa * a;
            aa %= mod;
        }
        a = (((a % mod) * (a % mod)) % mod);
        b >>= 1;
    }
    return aa;
}
int nCrRangeSum(int n, int r1, int r2)
{
    int p = mod;
    int num = 1, den = 1;
    int sum = !r1;
    int i = 0;
    while (i < r2)
    {
        num = (num * (n - i)) % p;
        den = (den * (i + 1)) % p;
        if (i - r1 >= -1 and !((i - r1 + 1) & 1))
        {
            sum += (num * power(den, p - 2)) % p;
            sum %= p;
        }
        i++;
    }
    return sum;
}
int solve(string A, string B, int N)
{
    vi count(4, 0);
    for (char c : A)
    {
        count[0] += (c == '1');
        count[1] += (c == '0');
    }
    for (char c : B)
    {
        count[2] += (c == '1');
        count[3] += (c == '0');
    }
    return nCrRangeSum(N, N - min(count[3], count[1]) - min(count[2], count[0]), min(count[1], count[2]) + min(count[0], count[3]));
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
    w(t) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b, n) << '\n';
    }
    return 0;
}