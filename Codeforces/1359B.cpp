#include<bits/stdc++.h>
#define ll int
using namespace std;
char a[100][1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        ll n,m,x,y;
        cin >> n >> m >>x >>y;
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll c=0;
            ll two=0;
            for(int j=0;j<m;j++){
                if(a[i][j]=='.'){
                    c++;
                }
            }
            for(int k=0;k<m;k+=1){
                if(a[i][k]=='.'){
                    if(k+1<m && a[i][k+1]=='.') {
                        two+=1;
                        k+=1;
                    }
                }
            }
            ll sum = two*y;
            ll single = c-(2*two);
            if(single>=0)
                sum+=single*x;
            if(two!=0)
                ans+=min(c*x,sum);
            else
                ans+=(c*x);
        }
        cout <<ans << '\n';
    }
    return 0;
}