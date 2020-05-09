//https://www.codechef.com/RC122020/problems/RECNDNOS
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
           int arr[n],max=0;
           int p,k,l;
           for(int j=0;j<n;j++)
           {
               cin>>arr[j];
           }
           for(int j=0;j<n;j++)
           {
               if(arr[j]>max)
               {
                   max=arr[j];
               }
           }
           int freq[max+1];
           for(int j=0;j<max+1;j++)
           {
               freq[j]=0;
           }
           for(int j=0;j<n;j++)
           {
               p=arr[j];
               freq[p]++;
               if(arr[j]==arr[j+1])
               {
                   j=j+1;
               }
           }
           k=0;
           for(int j=0;j<max+1;j++)
           {
               if(freq[j]>k)
               {
                   k=freq[j];
                   l=j;
               }
           }
           cout<<l<<endl;
    }
}