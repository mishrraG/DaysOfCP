#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a[5];
        int p;
        int s=0;
        for(int i=0;i<5;i++) {
            cin >> a[i];
            s+=a[i];
        }
        cin >> p;
        s=s*p;
        if(s<=120)
            cout <<"No\n";
        else
            cout <<"Yes\n";
    }
    return 0;
}