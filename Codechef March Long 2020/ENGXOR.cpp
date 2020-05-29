//https://www.codechef.com/MARCH20B/problems/ENGXOR
#include<bits/stdc++.h>
#define ll unsigned long int
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll size ,q;
        cin >> size >> q;
        ll a[size];
        int c=0;
        for(int i=0;i<size;i++){
            cin >>a[i];
            if(__builtin_popcount(a[i])%2==0)
                c++;
        }
        while(q--){
            int val;
            cin >>val;
            if(__builtin_popcount(val)%2==0)
            {
                cout  << c << " " << size-c << '\n';
            } else cout  << size-c << " " << c << '\n';
        }
    }
    return 0;
}