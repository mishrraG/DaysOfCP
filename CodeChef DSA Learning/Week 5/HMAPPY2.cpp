#include <iostream>
#define int long long
using namespace std;
int gcd(int a,int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,k;
        cin >> n >> a >>b >>k;
        int g = gcd(a, b);
        g = (a * b) / g;
        int f = n / a + n / b - 2 * (n / g);
        if (f < k)
            cout << "Lose\n";
        else
            cout << "Win\n";
    }
    return 0;
}