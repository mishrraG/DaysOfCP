//https://www.codechef.com/LRNDSA03/problems/DPAIRS
#include <bits/stdc++.h>
#define ll long long int
#define fr(i,n) for(i=0;i<n;i++)
#define ain(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define inf ((int)1e9+3)
using namespace std;
ll i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    ain(a,n)
    ain(b,m)
    int minb = inf,pos;
    fr(i,m)
        if(minb > b[i])
        {
            minb = b[i];
            pos = i;
        }
    fr(i,n)
        cout<<i<<" "<<pos<<"\n";

    int maxa = -inf;
    fr(i,n)
        if(maxa < a[i])
        {
            maxa = a[i];
            pos = i;
        }
    fr(i,m)
        if(b[i] != minb)
            cout<<pos<<" "<<i<<"\n";
    return 0;
}
