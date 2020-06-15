
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int n,ctr,low,high;
bool isEven(int x){
    return (x%2==0);
}
void odd()
{
    while (true){
        int mid = (int)(high + low) / 2;
        cout << mid << "\n";
        char c;
        cin >> c;
        if (c == 'E')
        {
            break;
        }
        if (low == high)
        {
            low = 1;
            high = n;
            ctr++;
            break;
        }
        if (!isEven(ctr))
            c=='G'?low = mid + 1:high = mid - 1;
        ctr++;
    }
}
void even(){
    while (true)
    {
        int mid = (int)(high + low) / 2;
        cout << mid << "\n";
        char c;
        cin >> c;
        if (c == 'E')
        {
            break;
        }
        if (isEven(ctr))
        {
            c=='G'?low = mid + 1:high = mid - 1;
        }
        ctr++;
    }
}
signed main()
{
    cin >> n;
    ctr = 1;
    low = 1, high = n;
    odd();
    even();
}