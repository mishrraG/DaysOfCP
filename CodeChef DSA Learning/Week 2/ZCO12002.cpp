// https://www.codechef.com/LRNDSA02/problems/ZCO12002
#define MAX 1000002
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	
    int n, x, y, t1, t2, duration=INT_MAX;
    cin>>n>>x>>y;
    int in[MAX], out[MAX];
    vector<pair<int, int>> contest;
    memset(in, -1, sizeof(int)*MAX);
    memset(out, -1, sizeof(int)*MAX);
    for(int i=0; i<n; i++) {
        cin>>t1>>t2;
        contest.push_back(make_pair(t1, t2));
    }
    for(int i=0; i<x; i++) {
        cin>>t1;
        in[t1]=t1;
    }
    for(int i=0; i<y; i++) {
        cin>>t1;
        out[t1]=t1;
    }
    t1=-1;
    for(int i=1; i<MAX; i++) {
        if(in[i]!=-1) t1=in[i];
        else in[i]=t1;
    }
    t1=-1;
    for(int i=MAX-1; i>0; i--) {
        if(out[i]!=-1) t1=out[i];
        else out[i]=t1;
    }
    for(auto i=contest.begin(); i!=contest.end(); i++) {
        if(in[i->first]!=-1 && out[i->second]!=-1 && ( out[i->second] - in[i->first]+1 < duration)) duration=out[i->second] - in[i->first]+1;
    }
    cout<<duration<<"\n";
    return 0;
}