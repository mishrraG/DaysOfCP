#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> gr1[500013];
    int a, c;
    for(int i = 0; i < m; ++i){
        cin >> a >> c;
        --a;
        --c;
        gr1[a].push_back(c);
        gr1[c].push_back(a);
    }
    int p[500013];
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    unordered_set<int> gr[500013];
    for(int i = 0; i < n; ++i){
        for(int j : gr1[i]){
            gr[i].insert(p[j] - 1);
        }
    }
    vector<pair<int,int> > b;
    for(int i = 0; i < n; ++i){
        pair<int,int> k;
        k.first = p[i] - 1;
        k.second = i;
        b.push_back(k);
    }
    sort(b.begin(), b.end());
    for(pair<int,int> i : b){
        int ci = i.second;
        int ct = i.first;
        for(int j = 0; j < ct; ++j){
            if(gr[ci].count(j) == 0){
                cout << -1;
                return 0;
            }
        }
        if (gr[ci].count(ct) != 0){
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < b.size(); ++i){
        cout << b[i].second + 1 << " ";
    }
}
