#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        int m=INT_MAX;
        for(int i=0;i<n-1;i++){
            int diff = abs(a[i]-a[i+1]);
            m=min(diff,m);
        }
        cout << m << '\n';
    }
}