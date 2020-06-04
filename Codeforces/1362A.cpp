#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,e,f,i,j,k=0,l=0;
        cin>>a>>b;
        if(b>a)
            swap(a,b);
        if(a==b)
            cout<<0<<endl;
        else if(a%b!=0)
            cout<<-1<<endl;
        else {
            c=a/b;
            while(1)
            {
                if(c%8==0)c=c/8;
                else if(c%4==0)c=c/4;
                else if(c%2==0)c=c/2;
                else
                {
                    l=1;
                    break;
                }
                k++;
                if(c==1)break;
            }
            if(l==1)
                cout<<-1<<'\n';
            else
                cout<<k<<'\n';
        }
    }
}