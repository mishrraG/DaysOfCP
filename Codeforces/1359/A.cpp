#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        lli n,m,k,ans=0,a,b,c;
        cin>>n>>m>>k;
        c=n/k;
        if(m<=c)
        {
            cout<<m<<"\n";
            continue;
        }
        m-=c;
        a=k-1;
        if(m%a==0)
            b=m/a;
        else
            b=m/a+1;
        ans=c-b;
        cout<<ans<<"\n";
    }
    return 0;
}