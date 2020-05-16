//https://www.hackerearth.com/challenges/competitive/may-circuits-20/algorithm/powerful-of-factorial-cb263e5b/
#include <iostream>
using namespace std;
int modulo(int a, int b, int n){
    long long x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b;
    cin >> a >> b ;
    cout << modulo(a,factmod(b,10),10)%10 << endl;
    return 0;
}
