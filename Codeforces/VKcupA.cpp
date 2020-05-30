#include <cstdio>

int n, k;
int T[51];

int main()
{
    scanf("%d %d", &n, &k);
    int i = 1;
    for(; i <= n; ++i)
    {
        scanf("%d", &T[i]);
        if(T[i] == 0 || T[i] < T[k]) break;
    }
    printf("%d\n", i - 1);
    return 0;
}