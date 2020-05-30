#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a<b)
        {
            int t=a;
            a=b;
            b=t;
        }
        int m=max(a,2*b);
        cout << m*m << '\n';
    }
}