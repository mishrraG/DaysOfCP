//https://www.codechef.com/LRNDSA02/submit/ZCO12001

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t=1;
    while(t--)
    {
        ll input,n,depth=0,d_pos,max=0,max_pos,count=0,pos,open=0 ;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>input;
            if(open==0)
            {
                pos=i+1;
                count=0;
            }

            count++;
            if(input==1)
                open++;
            if(input==2)
                open--;
            if(open>depth)
            {
                depth=open;
                d_pos=i+1;
            }
            if(max<count)
            {
                max=count;
                max_pos=pos;
            }

        }
        cout<<depth<<" "<<d_pos<<" "<<max<<" "<<max_pos<<"\n";
    }
    return 0;
}
