#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[60] = {0};
ll fib(ll f[], ll n)
{
    f[0] = 0;
    f[1] = 1;
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10;

    return f[n];
}

int findLastDigit(ll n)
{
    if(n<0)
        return 0;


    return f[n % 60];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    fib(f,60);
    while(t--)
    {
        ll n;
        cin>>n;
        ll i=1;
        while(i<=n)
        {
            i*=2;
        }
        if(i!=n)
            i/=2;

        cout<<findLastDigit(i-1)<<"\n";
    }
    return 0;
}