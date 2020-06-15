#include <iostream>
#define int long long
#define endl '\n'
using namespace std;
int a,b,c,p,q,r;
int gcd(int,int);
int gcd(long,long);
bool propo(int,int,int,int);
int result(int,int,int);
int32_t gcd(int32_t,int32_t);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        cin >> p >> q >> r;
        cin >> a >> b >>c;
        int res = result(p,q,r);
        cout << res << endl;
    }
    return 0;
}
int gcd(int a, int b)
    {
        return b==0?a:gcd(b,a%b);
    }
int gcd(long a, long b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (~a & 1)
    {
        if (b & 1)
            return gcd(a >> 1, b);
        else
            return gcd(a >> 1, b >> 1) << 1;
    }
    if (~b & 1)
        return gcd(a, b >> 1);
    if (a > b)
        return gcd((a - b) >> 1, b);

    return gcd((b - a) >> 1, a);
}
int32_t gcd(int32_t a, int32_t b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int result(int p, int q, int r) {
    if((a==p)+(b==q)+(c==r)>1)
        return 3-(a==p)-(b==q)-(c==r);
    if((a-p==b-q && a-p==c-r) || (propo(a, p, b, q) && propo(a, p, c, r) && propo(b, q, c, r)))
        return 1;
    if(c==r)
        return 1 + (a-p!=b-q && !propo(a, p, b, q));
    if(a==p)
        return 1 + (c-r!=b-q && !propo(c, r, b, q));
    if(b==q)
        return 1 + (a-p!=c-r && !propo(a, p, c, r));
    if(a==p || b==q || c==r)
        return 2;

    int remain=3;  
    if(propo(a-b, p-q, b-c, q-r)) 
        return 2;
    remain=min(remain, result(p+c-r, q+c-r, c)); 
    remain=min(remain, result(p+b-q, b, r+b-q));
    remain=min(remain, result(a, q+a-p, r+a-p));
    if(r && !(c%r)) remain=min(remain, result(p*c/r, q*c/r, c));
    if(q && !(b%q)) remain=min(remain, result(p*b/q, b, r*b/q));
    if(p && !(a%p)) remain=min(remain, result(a, q*a/p, r*a/p));
    if(propo(a+r-c,p,b+r-c,q)+propo(a+q-b,p,c+q-b,r)+propo(b+p-a,q,c+p-a,r))
        return 2;                       
    remain=min(remain, result(p, q+c-r, c));  
    remain=min(remain, result(p+c-r, q, c));
    remain=min(remain, result(p, b, r+b-q));
    remain=min(remain, result(p+b-q, b, r));
    remain=min(remain, result(a, q, r+a-p));
    remain=min(remain, result(a, q+a-p, r));
    if(r && !(c%r)) remain=min(remain, result(p, q*c/r, c));
    if(r && !(c%r)) remain=min(remain, result(p*c/r, q, c));
    if(q && !(b%q)) remain=min(remain, result(p, b, r*b/q));
    if(q && !(b%q)) remain=min(remain, result(p*b/q, b, r));
    if(p && !(a%p)) remain=min(remain, result(a, q, r*a/p));
    if(p && !(a%p)) remain=min(remain, result(a, q*a/p, r));
    return 1 + remain;
}
bool propo(int a, int p, int b, int q)
{
    if (((p==0) && (a!=0)) || ((q==0) && (b!=0)) || ((a!=0) && (b==0) && (q!=0)) || ((a==0) && (b!=0) && (p!=0)))
    {
        return false;
    }
    if ((gcd(a,p)!=0) && (gcd(b,q)!=0))
    {
        return (a % p) == 0 && (b % q) == 0 && a * gcd(b,q) == b * gcd(a,p) && p * gcd(b,q) == q * gcd(a,p);
    }
    if (p != 0)
    {
        return (a % p) == 0;
    }
    if (q != 0)
    {
        return (b % q) == 0;
    }
    return true;
}