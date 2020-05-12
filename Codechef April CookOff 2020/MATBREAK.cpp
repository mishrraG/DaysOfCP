//https://www.codechef.com/COOK117B/problems/MATBREAK
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll m=1000000007;

ll power(ll x, unsigned ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % m;
        n = n / 2;
        x = x * x % m;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a;
        a=a%m;
        ll s=0,p=a,k,b;
        for(ll i=1;i<=(2*n-1);i=i+2)
        {
            k=power(p,i);
            k=k%m;

            s=(s+k)%m;
            s=s%m;

            k=power(p,i+1);
            k=k%m;
            p=k;
        }
        cout<<s<<"\n";

    }


    return 0;
}
