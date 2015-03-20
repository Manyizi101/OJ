Matrix qMPow(Matrix &A, int n)
{
    Matrix rslt(A.N);
    rslt.unit();
    if (n == 0) return rslt;
    while (n)
    {
        if (n & 1) // 若幂为奇数
        {
            rslt = rslt * A;
        }
        A = A * A;
        n >>= 1; // 右位移等价于除以2 	
    }
    return rslt;
}
