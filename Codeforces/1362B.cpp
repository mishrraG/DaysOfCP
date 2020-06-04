#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,e=0,i,j,l=0;
        cin>>a;
        map<int,int>n,m;
        vector<int>v,x;
        for(i=1;i<=a;i++)
        {
            cin>>b;m[b]++;v.push_back(b);l=max(l,b);
        }
        sort(v.begin(),v.end());
        for(i=1;i<=l*2;i++)
        {
            x.clear();
            n.clear();
            for(j=0;j<a;j++)
            {
                c=v[j]^i;
                n[c]++;
                x.push_back(c);
                if(n[c]>m[c])
                    break;
            }
            sort(x.begin(),x.end());
            if(x==v){
                cout<<i<<'\n';
                e=1;
                break;
            }
        }
        if(!e)
            cout<<-1<<'\n';
    }}