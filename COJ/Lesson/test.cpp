bool IsPrime(unsigned n)  //此处n是一个大于2的整数
{
	for (unsigned i = 2; i < n / 2 + 1; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}