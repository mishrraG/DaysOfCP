#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,p=1;
    cin>>t;
    long long int mod=1e9;
    while(t--)
    {
        string s;
        cin>>s;
        long long int x=0,y=0,i;
        stack<long long int>ss;
        long long int temp=1LL;
        ss.push(temp);
        for(i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                temp=((long long int)(s[i]-'0')*temp)%mod;
                ss.push(temp);
            }
            else if(s[i]==')')
            {
                ss.pop();
                temp=ss.top();
            }
            else
            {
                if(s[i]=='N')
                    x=(x-temp)%mod;
                else if(s[i]=='S')
                    x=(x+temp)%mod;
                else if(s[i]=='E')
                    y=(y+temp)%mod;
                else if(s[i]=='W')
                    y=(y-temp)%mod;
            }
        }
        x=(x+mod)%mod;
        y=(y+mod)%mod;
        x++;
        y++;
        cout<<"Case #"<<p<<": "<<y<<" "<<x<<endl;
        p++;
    }
    return 0;
}
