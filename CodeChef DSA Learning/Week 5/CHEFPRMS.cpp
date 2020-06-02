#include <iostream>
using namespace std;
bool isPrime(int x)
{
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}
bool isSemiPrime(int a)
{
    for(int i = 2; i*i < a; i++)
    {
        if(a % i == 0 && isPrime(i) && isPrime(a/i))
            return 1;
    }
    return 0;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int f=0;
        for(int i = 4; i <= n/2; i++)
        {
            int j = n - i;

            if(isSemiPrime(i) && isSemiPrime(j))
            {
                cout << "YES\n";
                f=1;
                break;

            }
        }
        if(f==0)
            cout << "NO\n";
    }
    return 0;
}