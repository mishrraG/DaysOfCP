//Question Link : https://www.codechef.com/APRIL20B/problems/ANSLEAK
# include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n, m, k, **A, *hash;
        scanf("%d%d%d",&n,&m,&k);
        A = new int*[n];
        for (int i=0;i<n;i++) {A[i] = new int[k];}
        for (int i=0;i<n;i++) {
            for(int j=0;j<k;j++){
                scanf("%d",&A[i][j]);
            }
        }
        printf("\n\n");
        int rep[n];
        for (int i=0;i<n;i++) {
            hash = new int[m+1];
            for (int j=0;j<m+1;j++) { hash[j] = 0; }
            int ind_max=0, max=0;
            for (int j=0;j<k;j++) { hash[A[i][j]]++;   }

            for (int j=1;j<m+1;j++) {
                if (hash[j]>max)  { max=hash[j];       ind_max=j;}
            }
            rep[i]=ind_max;
            delete[] hash;
        }
        for(int i = n-1;i>=0;i--)
            printf("%d ",rep[i]);
    }
    return 0;
}
