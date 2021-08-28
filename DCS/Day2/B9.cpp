void sort012(int a[], int n)
{
    int ctr[3] = {0};
    for (int i = 0; i < n; i++)
        ctr[a[i]]++;
    int c = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < ctr[i]; j++)
        {
            a[c++] = i;
        }
    }
}
