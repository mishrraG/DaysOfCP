#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void spiralFill(int m, int n)
{
    int cp=m;
    int a[m][n];
    int val = 1;
    int k = 0, l = 0;
    while (k < m && l < n)
    {
        for (int i = l; i < n; ++i)
            a[k][i] = val++;
        k++;
        for (int i = k; i < m; ++i)
            a[i][n-1] = val++;
        n--;
        if (k < m)
        {
            for (int i = n-1; i >= l; --i)
                a[m-1][i] = val++;
            m--;
        }
        if (l < n)
        {
            for (int i = m-1; i >= k; --i)
                a[i][l] = val++;
            l++;
        }
    }
    for(int i=0;i<cp;i++){
        for(int j=0;j<cp;j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        spiralFill(n,n);
    }
}