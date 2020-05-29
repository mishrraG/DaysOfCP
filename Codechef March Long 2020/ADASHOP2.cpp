//https://www.codechef.com/MARCH20B/problems/ADASHOP2
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<array<int, 2>> moves;
    moves.push_back({(r+c)/2, (r+c)/2});
    moves.push_back({1, 1});
    for(int i=4; i<=8; i+=2) {
        moves.push_back({i/2, i/2});
        moves.push_back({1, i-1});
        moves.push_back({i-1, 1});
        moves.push_back({i/2, i/2});
    }
    for(int i=10; i<=16; i+=2) {
        moves.push_back({i/2, i/2});
        moves.push_back({i-8, 8});
        moves.push_back({8, i-8});
        moves.push_back({i/2, i/2});
    }
    cout << moves.size() << "\n";
    for(array<int, 2> a : moves)
        cout << a[0] << " " << a[1] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}