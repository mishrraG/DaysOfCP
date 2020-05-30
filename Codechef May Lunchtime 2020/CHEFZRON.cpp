#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> pos)
{
    long long m=pos.size();
    long long i;
    vector<int> ta(m+1,0),nt(m+1,0);
    ta[0]=pos[0];
    nt[0]=0;
    for(i=1;i<m;i++)
    {
        ta[i]=min(nt[i-1]+pos[i],ta[i-1]+pos[i]);
        nt[i]=ta[i-1];
    }
    long long ans1=ta[m-1];
    reverse(pos.begin(),pos.end());
    vector<int> ta1(m+1,0),nt1(m+1,0);
    ta1[0]=pos[0];
    nt1[0]=0;
    for(i=1;i<m;i++)
    {
        ta1[i]=min(nt1[i-1]+pos[i],ta1[i-1]+pos[i]);
        nt1[i]=ta1[i-1];
    }
    long long ans2=ta1[m-1];
    return min(ans1,ans2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int>p,t;
        for(int i=0;i<n;i++){
            if(v[i]==1)
                t.push_back(i);
        }
        if(t.size()==0) {
            cout << 0 << '\n';
            continue;
        }
        if(t.size()==1)
        {
            cout << -1 << '\n';
            continue;
        }
        for(int i=0;i<t.size()-1;i++)
        {
            p.push_back(t[i+1]-t[i]);
        }
        p.push_back(t[0]+(n)-t.back());
        cout<<solve(p)<<endl;
    }
    return 0;
}