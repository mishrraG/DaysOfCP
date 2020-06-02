#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define nl cout<<endl
#define P 1000000007
#define MOD(x) ((x%P)+P)%P
int main()
{
    fastio();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        bool flag=false;
        ll res=-1;
        for(ll i = 1; i <= sqrt(n); i++)
        {
            if(n%i==0 && i!=n/i)
            {
                ll m=(n/i+i)/2;
                ll x=(n/i-i)/2;
                if(x*x+n == m*m)
                {
                    if(!flag) res=x;
                    else res=min(res, x);
                    flag=true;
                }
            }
        }
        if(flag) res=res*res;
        cout<<res,nl;
    }
    return 0;
}