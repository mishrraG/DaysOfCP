//https://www.codechef.com/MAY20B/problems/TRPLSRT
#include <bits/stdc++.h>
#define f(a,b) a.erase(b)
#define eq(a,b) a==b
#define mp map<int,bool>
using namespace std;
inline int inc(int x){
    return x+1;
}
inline int dec(int x){
    return x-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    int n,kn;
    cin>>t;
    while(t)
    {
        t=dec(t);
        cin>>n>>kn;
        int a[n+1];
        int b[n+1];
        vector<bool>orig_a(n+1);
        vector<bool>orig_b(n+1);
        mp comp_a;
        mp comp_b;
        vector<int>two_a(n+1);
        vector<int>two_b(n+1);
        a[0]=INT_MAX;
        a[0]=true;
        long long freq_a=n,freq_b=n;
        for(int i=1;i<=n;i=inc(i))
        {
            cin>>a[i];
            b[i]=a[i];
            comp_a[i]=false;
            comp_b[i]=false;
            if(!(a[i]-i))
            {
                orig_a[i]=orig_b[i]=true;
                comp_a[i]=true;
                comp_b[i]=true;
                f(comp_a,i);
                f(comp_b,i);
                freq_a--,freq_b--;
            }
        }
        int v1=0,v2=0,v3=0;
        int k=0;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(!orig_a[i])
            {
                v1=i;
                v2=a[i];
                v3=a[a[i]];
                if(eq(v1,a[v3]) && eq(a[v1],v2))
                {
                    k++;
                    flag=1;
                    orig_a[v1]=orig_a[v2]=orig_a[v3]=true;
                    f(comp_a,v1),  f(comp_a,v2), f(comp_a,v3);
                    a[v2]=v2, a[v3]=v3, a[v1]=v1;
                    freq_a-=3;
                    break;
                }
            }
        }
        for(int i=1;i<=n;)
        {
            if(orig_a[i])
            {
                i++;
                continue;
            }
            else if(eq(freq_a,2))
            {
                k=0;
                break;
            }
            v1=i;
            v2=a[i];
            v3=a[a[i]];
            if(eq(v1,v3))
            {
                two_a[v1]=v2;
                if(eq(two_a[v1],v2) && eq(two_a[v2],v1))
                {
                    mp::reverse_iterator j;
                    for (j = comp_a.rbegin(); j != comp_a.rend(); j++)
                    {
                        if(j->first!=v2 && (j->first!=v1))
                        {
                            v3=j->first;
                            break;
                        }
                    }
                }
                else
                {
                    i++;
                    continue;
                }
            }
            k++;
            int x= a[v2];
            int y=a[v3];
            a[v2]=a[i], orig_a[v2]=true,freq_a--, f(comp_a,v2);
            a[v3]=x;
            if(eq(v3,x))
            {
                orig_a[v3]=true;
                freq_a--;
                f(comp_a,v3);
            }

            a[v1]=y;
            if(eq(v1,y))
            {
                orig_a[v1]=true;
                freq_a--;
                f(comp_a,v1);
            }
        }

        if(eq(freq_a,2) || k>kn)
        {
            cout<<-1<<endl;
        }

        else
        {
            cout<<k<<endl;
            if(flag)
            {
                for(int i=1;i<=n;i++)
                {
                    if(!orig_b[i])
                    {
                        v1=i;
                        v2=b[i];
                        v3=b[b[i]];
                        if(eq(v1,b[v3]) && eq(b[v1],v2))
                        {
                            k++;
                            cout<<v1<<" "<<v2<<" "<<v3<<endl;
                            orig_b[v1]=true, orig_b[v2]=true,orig_b[v3]=true;
                            f(comp_b,v1),  f(comp_b,v2), f(comp_b,v3);
                            b[v2]=v2, b[v3]=v3, b[v1]=v1;
                            freq_b-=3;
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=n;)
            {
                if(orig_b[i])
                {
                    i++;
                    continue;
                }
                else if(eq(freq_b,2))
                {
                    break;
                }

                v1=i;
                v2=b[i];
                v3=b[b[i]];
                if(v1==v3)
                {
                    two_b[v1]=v2;
                    if(eq(two_b[v1],v2) && eq(two_b[v2],v1))
                    {
                        mp::reverse_iterator j;
                        for (j = comp_b.rbegin(); j != comp_b.rend(); j++)
                        {
                            if(j->first!=v2 && (j->first!=v1))
                            {
                                v3=j->first;
                                break;
                            }
                        }
                    }
                    else
                    {
                        i++;
                        continue;
                    }

                }
                cout<<v1<<" "<<v2<<" "<<v3<<endl;
                k++;
                int x= b[v2];
                int y=b[v3];
                b[v2]=b[i], orig_b[v2]=true,freq_b--, f(comp_b,v2);
                b[v3]=x;
                if(eq(v3,x))
                {
                    orig_b[v3]=true;
                    freq_b--;
                    f(comp_b,v3);
                }
                b[v1]=y;
                if(eq(v1,y))
                {
                    orig_b[v1]=true;
                    freq_b--;
                    f(comp_b,v1);
                }
            }
        }
    }
    return 0;
}