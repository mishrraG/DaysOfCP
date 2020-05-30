#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int> dig(int n)
{
    int largest = 0;
    int smallest = 9;

    while (n) {
        int r = n % 10;
        largest = max(r, largest);
        smallest = min(r, smallest);
        n = n / 10;
    }
    return {smallest,largest};
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        for(int i=1;i<b;i++)
        {
            if(dig(a).first*dig(a).second>0)
                a+=dig(a).first*dig(a).second;
            else
                break;
        }
        cout << a << '\n';
    }
    return 0;
}