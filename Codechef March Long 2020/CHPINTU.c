//https://www.codechef.com/MARCH20B/problems/CHPINTU
#include<stdio.h>
int main(){
    int p;
    scanf("%d",&p);
    int z[p];
    for(int i=0;i<p;i++) {
        int a;
        int count1=0;
        int p,w;
        scanf("%d",&p);
        scanf("%d",&w);
        int l[p],h[p];
        for(int j=0;j<p;j++) {
            scanf("%d",&l[j]);
        }
        for(int d=0;d<p;d++) {
            scanf("%d",&h[d]);
        }
        int max=10000000;
        for(int y=1;y<=w;y++) {
            a=0;
            int count=0;
            for(int m=0;m<p;m++) {
                if(l[m]==y) {
                    count=count+h[m];
                    a=1;
                }   
            }
            if(count<max&&a==1){
                max=count;
            }
            count=0;
        }
        z[i]=max;
    }
    for(int i=0;i<p;i++) {
        printf("%d\n",z[i]);
    }
}
