int maxSubarraySum(int a[], int n)
{
    int mf = INT_MIN, me = 0;

    for (int i = 0; i < n; i++)
    {
        me = me + a[i];
        if (mf < me)
            mf = me;

        if (me < 0)
            me = 0;
    }
    return mf;
}