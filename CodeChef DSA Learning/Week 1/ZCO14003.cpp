#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,x,maxx;
    cin>>N;
    int A[N];
    for(long long int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sort(A,A+N);
    maxx=A[0]*(N-0);
    for(long long int i=1;i<N;i++)
    {
        x=A[i]*(N-i);
        if(x>=maxx)
        {
            maxx=x;
        }
    }
    cout<<maxx;
return 0;
}