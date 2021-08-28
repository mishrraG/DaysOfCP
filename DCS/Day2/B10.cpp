int doUnion(int a[], int n, int b[], int m)
{
    set<int> val(b, b + m);
    for (int i = 0; i < n; i++)
    {
        val.insert(a[i]);
    }
    return val.size();
}