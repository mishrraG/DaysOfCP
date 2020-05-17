#include <bits/stdc++.h>
using namespace std;
int solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n ,q;
    cin >> n >>q;
    vector<int>v(n);
    int sum =0;
    int qc=1;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    while (qc<=q){
        char c;
        int x,y;
        cin >> c >> x >>y;
        if(c=='Q')
        {
            int cp=1;
            for(int i=x-1;i<y;i++)
            {
                sum+=v[i]*cp*(i-(x-2));
                cp=cp*-1;
            }
        }
        else if(c=='U')
        {
            v[x-1]=y;
        }
        qc++;
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, i=1;
    cin >> t;
    while(i<=t) {
        cout << "Case #" << i << ": "<<solve() << endl;
        ++i;
    }
    return 0;
}