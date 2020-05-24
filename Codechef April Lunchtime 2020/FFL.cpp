#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,s;
        cin>>n>>s;
        int arr[n];
        int brr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        for(int j=0;j<n;j++)
        {
            cin>>brr[j];
        }
        int min1=100;
        int min2=100;
        for(int j=0;j<n;j++)
        {
            if(arr[j]<min1&&brr[j]==0)
            {
                min1=arr[j];
            }
            if(arr[j]<min2&&brr[j]==1)
            {
                min2=arr[j];
            }
        }
        int res=100-s;
        if(min1+min2>res)
        {
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"yes"<<endl;
        }
    }
}
