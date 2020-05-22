//https://www.codechef.com/LRNDSA05/problems/ZACKHAN
#include <iostream>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (~a & 1)
    {
        if (b & 1)
            return gcd(a >> 1, b);
        else
            return gcd(a >> 1, b >> 1) << 1;
    }
    if (~b & 1)
        return gcd(a, b >> 1);
    if (a > b)
        return gcd((a - b) >> 1, b);
    return gcd((b - a) >> 1, a);
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b)<<endl;
    }
    return 0;
}

