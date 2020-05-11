// https://www.codechef.com/MAY20B/problems/COVID19
#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0){
        int n;
        scanf("%d",&n);
        int pos[n];
        for(int i=0;i<n;i++)
            scanf("%d",&pos[i]);
        int m0=0;
        int m1=1;
        int prs=1;
        for(int i=0;i<n-1;i++){
            if(pos[i+1]-pos[i]<=2){
                prs++;
            }
            else{
                m1=(m1>prs)?m1:prs;
                if(!m0){
                    m0=m1;
                }
                else{
                    m0=(m0<prs)?m0:prs;
                }
                prs=1;
            }
        }
        m1=(m1>prs)?m1:prs;
        if(!m0){
            m0=m1;
        }
        else{
            m0=(m0<prs)?m0:prs;
        }
        printf("%d %d\n",m0,m1);
    }
    return 0;
}
