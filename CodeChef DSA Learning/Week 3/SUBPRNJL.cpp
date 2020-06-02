#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
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
        ll n,k,ans=0;
        cin>>n>>k;
        vector<ll>a(n);
        loop(i,0,n)	cin>>a[i];

        loop(l,0,n)
        {
            ll fr[2001]={};
            ll mn = a[l];
            ll mx = a[l];
            loop(r,l,n)
            {
                fr[a[r]]++;
                mx = max(mx,a[r]);
                mn = min(mn,a[r]);

                ll sz = r-l+1;
                ll m = (k-1)/sz + 1;
                ll ind = (k-1)/m;
                ll num;

                if( ind == 0 )
                    num = mn;
                else if( ind == sz-1 )
                    num = mx;
                else
                {
                    ll cur=0;
                    ll rind = sz - ind;
                    for(ll i=mx;i>=mn;i--)
                    {
                        cur += fr[i];
                        if( cur >= rind )
                        {
                            num = i;
                            break;
                        }
                    }
                }

                if( fr[fr[num]] )
                    ans++;
            }
        }
        cout<<ans,nl;
    }



    return 0;
}